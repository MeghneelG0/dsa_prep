import sys
import importlib
import argparse
import os

parser = argparse.ArgumentParser()
parser.add_argument("module", help="Name of the Python module, e.g., 'pattern.pattern1'")
args = parser.parse_args()

# Redirect input/output
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

# Add current folder to Python path (so subfolders can be imported as packages)
sys.path.append(os.getcwd())

# Import and run
mod = importlib.import_module(args.module)
mod.solve()
