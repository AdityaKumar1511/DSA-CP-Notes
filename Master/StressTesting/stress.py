import os
import subprocess
import sys

# 1. Compile all files first using subprocess
print("Compiling files...")
try:
    subprocess.run(["g++", "-O3", "generator.cpp", "-o", "generator"], check=True)
    subprocess.run(["g++", "-O3", "brute.cpp", "-o", "brute"], check=True)
    subprocess.run(["g++", "-O3", "solution.cpp", "-o", "solution"], check=True)
    print("Compilation done. Starting stress test...\n")
except subprocess.CalledProcessError:
    print("❌ Compilation failed! Check your C++ code for syntax errors.")
    sys.exit(1)

# Determine the correct executable prefix based on OS
is_windows = os.name == 'nt'
gen_exe = "generator.exe" if is_windows else "./generator"
brute_exe = "brute.exe" if is_windows else "./brute"
sol_exe = "solution.exe" if is_windows else "./solution"

# 2. Loop to test your code
for i in range(1, 10001):
    # Step A: Run generator and catch its output
    gen_result = subprocess.run([gen_exe], capture_output=True, text=True, check=True)
    tc_input = gen_result.stdout
    
    # Save input to input.txt just in case we need to look at it later
    with open("input.txt", "w") as f:
        f.write(tc_input)
        
    # Step B: Feed input directly into brute and solution
    brute_result = subprocess.run([brute_exe], input=tc_input, capture_output=True, text=True, check=True)
    sol_result = subprocess.run([sol_exe], input=tc_input, capture_output=True, text=True, check=True)
    
    brute_out = brute_result.stdout.strip()
    sol_out = sol_result.stdout.strip()
    
    # Step C: Compare outputs
    if brute_out != sol_out:
        print(f"\n❌ Mismatch found on test case {i}!")
        print("\n--- INPUT ---")
        print(tc_input.strip())
        print(f"\nExpected (Brute): {brute_out}")
        print(f"Your Code Output: {sol_out}")
        sys.exit(0)
    
    # 👇 ONLY PRINT EVERY 500 TEST CASES TO SPEED IT UP
    elif i % 500 == 0:
        print(f"Passed test case {i}...", end="\r")

print("\nAll 10,000 tests passed successfully! Your solution is rock solid. 🎉")