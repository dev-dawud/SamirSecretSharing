# SamirSecretSharing

This project is a C++ implementation of **Shamir's Secret Sharing (SSS)**.
The concept of Shamir's Secret Sharing is to split a secret `S` into `n` separate shares (points on a polynomial) so that at least `t` shares (the threshold) are required to reconstruct the original secret, while fewer than `t` shares reveal no information about it.
In the real world, this concept is a key building block for secure key management and backups.
For example, instead of storing a master password or cryptographic recovery key in one single place (where losing it means permanent loss, and stealing it means a full breach), you can split it into `n = 5` shares and distribute them to 5 trusted people or locations.
Even if 2 shares are lost or stolen, the secret stays safe and recoverable-only when at least `t = 3` shares are combined can the secret `S` be reconstructed mathematically.

This project separates the logic into two classes (`Generate` and `Reconstruct`) to keep share creation and secret recovery cleanly structured. `Generate` defines the secret and generates the secret shares from a random polynomial, while `Reconstruct` takes `t` shares and recovers `S` using Lagrange interpolation.

The flow of the implemented **Shamir's Secret Sharing** scheme works as follows:
1. **Setup:** Define the secret `S`, the total number of shares `n`, the threshold `t`, and a large prime `p = 2^255 - 19` (currently configured in [generate.h](src/header/generate.h) with `S = 7`, `n = 5`, `t = 3`).
2. **Polynomial Construction:** Calculate the polynomial degree `t - 1` and generate `t - 1` random coefficients modulo `p` using GMP (`gmp_randclass`). Together with `S` as the constant term, this forms `f(x) = S + a1*x + a2*x^2 + ... (mod p)`.
3. **Share Generation:** Evaluate `f(x) mod p` for `x = 1, ..., n` to produce `n` share points `P(x, y)`.
4. **Point Selection:** Pass `t` shares (`calcGrade + 1` points) to `Reconstruct` for recovery.
5. **Reconstruction (Lagrange Interpolation):** Compute `f(0) mod p` from the `t` shares using Lagrange basis polynomials and modular inverses (`mpz_invert`) modulo `p` to recover `S`.

## Project Structure
- [src/main.cpp](src/main.cpp) - Entry point connecting `Generate` and `Reconstruct`
- [src/header/generate.h](src/header/generate.h) / [src/cpp/generate.cpp](src/cpp/generate.cpp) - Parameter setup, polynomial generation, and share calculation
- [src/header/reconstruct.h](src/header/reconstruct.h) / [src/cpp/reconstruct.cpp](src/cpp/reconstruct.cpp) - Share selection and Lagrange interpolation modulo `p`

## Requirements
- C++11 or later
- GMP Library (`gmp` / `gmpxx`) for large integer arithmetic
- Any standard C++ compiler (e.g., GCC, Clang, or MSVC)

## Installation
Use `git clone` to download the project.

```bash
git clone https://github.com/dev-dawud/SamirSecretSharing.git
cd SamirSecretSharing
```

Make sure the GMP library (`gmp` and `gmpxx`) is installed and linked in your build setup.
Compile the source files in `src/` (`src/main.cpp`, `src/cpp/generate.cpp`, `src/cpp/reconstruct.cpp`) with optimizations enabled for smooth performance.

## Usage
Run the compiled binary (`./SamirSecretSharing`).
To test different values, adjust `S`, `n`, and `t` in [src/header/generate.h](src/header/generate.h) and recompile.

Example output (coefficients and `y`-values vary on each run because the polynomial is random):
```text
For this round, use the following parameters:
S = 7
n = 5
t = 3
p = 57896044618658097711785492504343953926634992332820282019728792003956564819949

Your polynom is a 2 second degree.
...
Points for reconstruction:
P(1, ...)
P(2, ...)
P(3, ...)

Reconstructed Secret S = 7
```

## Contributing
Contributions are welcome! (Please follow the existing code style)
If you have any suggestions or improvements, please feel free to submit a pull request.

## Acknowledgments
- Thanks to Gemini for help with debugging and math edge cases (every AI-generated code block/line is marked with `"AI-Generated"`)
- DeepL for helping with translating README files and git commits into English

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
