# export_decomp.py — Ghidra headless post-script.
# Dumps, for every function in the program:
#   - name, entry address, size
#   - basic-block / edge counts from the decompiler CFG model
#   - the full decompiled C
# Usage: analyzeHeadless <proj> <projname> -import <bin> -scriptPath <dir> \
#            -postScript export_decomp.py <outfile>
import sys

from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor

outpath = args[0] if len(args) > 0 else "/tmp/decomp.txt"
monitor = ConsoleTaskMonitor()
program = currentProgram
fm = program.getFunctionManager()

decomp = DecompInterface()
decomp.openProgram(program)

lines = []
fm = program.getFunctionManager()
funcs = sorted(fm.getFunctions(True), key=lambda fn: fn.getEntryPoint().getOffset())
for fn in funcs:
    name = fn.getName()
    entry = fn.getEntryPoint().getOffset()
    body = fn.getBody()
    size = body.getNumAddresses() if body else 0
    lines.append("===== FUNCTION %s @ 0x%x size=%d =====" % (name, entry, size))
    res = decomp.decompileFunction(fn, 60, monitor)
    if res is not None and res.decompileCompleted():
        ccm = res.getCCodeModel()
        if ccm is not None:
            bbs = ccm.getBasicBlocks()
            nedges = 0
            for bb in bbs:
                nedges += len(bb.getOutEdges())
            lines.append("CFG blocks=%d edges=%d" % (len(bbs), nedges))
        cfn = res.getDecompiledFunction()
        if cfn is not None:
            lines.append(cfn.getC())
    else:
        lines.append("(decompile failed)")

with open(outpath, "w") as f:
    f.write("\n".join(lines))
    f.write("\n")

print("wrote " + outpath)