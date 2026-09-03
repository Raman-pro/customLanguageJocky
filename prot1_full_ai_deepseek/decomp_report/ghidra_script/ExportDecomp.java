// ExportDecomp.java — Ghidra headless post-script (Java).
// Dumps every function's name/entry/size, decompiler CFG block+edge counts,
// and full decompiled C to the output file (first script arg).
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.pcode.PcodeBlockBasic;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class ExportDecomp extends GhidraScript {

    @Override
    public void run() throws Exception {
        String outpath = (getScriptArgs().length > 0) ? getScriptArgs()[0] : "/tmp/decomp.txt";
        FunctionManager fm = currentProgram.getFunctionManager();
        DecompInterface decomp = new DecompInterface();
        decomp.openProgram(currentProgram);

        List<Function> funcs = new ArrayList<>();
        for (Function f : fm.getFunctions(true)) {
            funcs.add(f);
        }
        funcs.sort((a, b) -> Long.compare(a.getEntryPoint().getOffset(), b.getEntryPoint().getOffset()));

        StringBuilder sb = new StringBuilder();
        for (Function fn : funcs) {
            sb.append("===== FUNCTION ").append(fn.getName())
              .append(" @ 0x").append(Long.toHexString(fn.getEntryPoint().getOffset()))
              .append(" size=").append(fn.getBody().getNumAddresses()).append(" =====\n");
            DecompileResults res = decomp.decompileFunction(fn, 60, monitor);
            if (res != null && res.decompileCompleted() && res.getHighFunction() != null) {
                List<PcodeBlockBasic> bbs = res.getHighFunction().getBasicBlocks();
                int blocks = bbs.size();
                int edges = 0;
                for (PcodeBlockBasic bb : bbs) {
                    edges += bb.getOutSize();
                }
                sb.append("CFG blocks=").append(blocks).append(" edges=").append(edges).append("\n");
                sb.append(res.getDecompiledFunction().getC()).append("\n");
            } else {
                sb.append("(decompile failed)\n");
            }
        }

        try (PrintWriter pw = new PrintWriter(outpath)) {
            pw.print(sb.toString());
        }
        println("wrote " + outpath);
    }
}