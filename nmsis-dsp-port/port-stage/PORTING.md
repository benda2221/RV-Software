# Full NMSIS-DSP Test Migration

`vendor/NMSIS/DSP` is a structure-preserving copy of the upstream DSP package:

- `Source`, `Include`, and `PrivateInclude`: complete algorithm implementation
- `Benchmark`: all standalone C benchmark test programs and test data
- `Test`: legacy C correctness tests and reference implementations
- `Testing`: CMSIS-style C++ framework, patterns, generators, and suites

Zircon-specific files are isolated under `port/`. Include `port/include` before
the vendor include directories. Benchmark timing macros are intentionally
no-ops. Test randomness is deterministic. No `libm` implementation is supplied.

The migration inventory is in `manifests/dsp_tests.csv`. Every source is marked
`source_migrated`; `deferred_dependencies` identifies tests that cannot yet be
linked or executed because they require `libm`, float16/vector support, or the
C++ pattern-I/O runtime.

Refresh the full vendor copy and regenerate manifests with:

```sh
sh tools/sync_all_nmsis_dsp.sh
python3 tools/generate_manifest.py
```

These commands copy and classify sources only. They do not build or run tests.
