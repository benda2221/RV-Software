#!/usr/bin/env python3
import tempfile
import unittest
from pathlib import Path

import compare_benchmark_results as compare


class HashRegionTest(unittest.TestCase):
    @staticmethod
    def item(name, decl="output[1024]"):
        return {"name": name, "decl": decl}

    def test_partial_convolution_hashes_requested_samples(self):
        self.assertEqual(
            compare.hash_region(
                "convPartial_riscv_conv_partial_q31",
                self.item("conv_partial_q31_output"),
            ),
            (
                "conv_partial_q31_output + firstIndex",
                "(uint32_t)(numPoints * sizeof(conv_partial_q31_output[0]))",
            ),
        )

    def test_convolution_hashes_defined_output_length(self):
        self.assertEqual(
            compare.hash_region(
                "conv_riscv_conv_q15", self.item("conv_q15_output")
            ),
            (
                "conv_q15_output",
                "(uint32_t)((ARRAYA_SIZE_Q15 + ARRAYB_SIZE_Q15 - 1u) * sizeof(conv_q15_output[0]))",
            ),
        )

    def test_correlation_skips_unwritten_padding(self):
        data, length = compare.hash_region(
            "correlate_riscv_correlate_q7", self.item("correlate_q7_output")
        )
        self.assertIn("ARRAYA_SIZE_Q7 - ARRAYB_SIZE_Q7", data)
        self.assertEqual(
            length,
            "(uint32_t)((ARRAYA_SIZE_Q7 + ARRAYB_SIZE_Q7 - 1u) * sizeof(correlate_q7_output[0]))",
        )

    def test_decimator_hashes_block_size_divided_by_factor(self):
        self.assertEqual(
            compare.hash_region(
                "firDecimate_riscv_fir_decimate_q31",
                self.item("decimate_q31_output"),
            ),
            (
                "decimate_q31_output",
                "(uint32_t)((TEST_LENGTH_SAMPLES / M) * sizeof(decimate_q31_output[0]))",
            ),
        )

    def test_scalar_mat_mult_does_not_hash_scratch(self):
        self.assertIsNone(
            compare.hash_region(
                "matMult_riscv_mat_mult_q15", self.item("q15_output_back")
            )
        )

    def test_instrumentation_is_idempotent(self):
        source = """\
#include <stdint.h>
BENCH_DECLARE_VAR();
void conv_riscv_conv_q15(void)
{
    q15_t conv_q15_output[2 * max(ARRAYA_SIZE_Q15, ARRAYB_SIZE_Q15)];
    BENCH_END(riscv_conv_q15);
}
"""
        with tempfile.TemporaryDirectory() as tmpdir:
            path = Path(tmpdir) / "case.c"
            path.write_text(source)
            compare.instrument_file(path)
            first = path.read_text()
            compare.instrument_file(path)
            self.assertEqual(first, path.read_text())


if __name__ == "__main__":
    unittest.main()
