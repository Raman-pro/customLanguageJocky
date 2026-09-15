# Legacy Prototypes Archive

This directory archives earlier prototypes of the **JOCKY** language compiler developed prior to the final LLVM-based architecture (`prot2_llvm_full_ai_deepseek`).

---

## Prototypes

| Directory | Architecture | Status | Notes |
|---|---|---|---|
| [`prot1_full_ai/`](./prot1_full_ai/) | Initial architectural plan | Archived | Initial project specification and feature requirements. |
| [`prot1_full_ai_deepseek/`](./prot1_full_ai_deepseek/) | JOCKY-to-C Transpiler | Superseded by Prot 2 | Transpiled `.jk` code into C and used `clang`/`gcc` for codegen. Validated the language syntax and basic opaque predicates, but was superseded by direct LLVM IR compilation in Prot 2 to avoid relying on external C toolchains and to enable true binary-level polymorphism. |

> [!NOTE]
> The active, final project codebase is located at [`../prot2_llvm_full_ai_deepseek/`](../prot2_llvm_full_ai_deepseek/).
