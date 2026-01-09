#!/usr/bin/env python3

def garden_operations() -> None:
    """
    Demonstrates the various types of exceptions
    """
    print("Testing ValueError...")
    try:
        int("abc")
    except ValueError:
        print("Caught ValueError: invalid literal for int()\n")

    print("Testing ZeroDivisionError...")
    try:
        print(f"{7 / 0}")
    except ZeroDivisionError:
        print("Caught ZeroDivisionError: division by zero\n")

    print("Testing FileNotFoundError...")
    try:
        open("missing.txt", "r")
    except FileNotFoundError:
        print("Caught FileNotFoundError: No such file 'missing.txt'\n")

    print("Testing KeyError...")
    try:
        garden: dict = {"Rose": 26}
        print(garden["missing_plant"])
    except KeyError:
        print("Caught KeyError: 'missing\\_plant'\n")


def test_error_types() -> None:
    """
    Demonstrates that you can catch several exceptions at once
    """
    print("=== Garden Error Types Demo ===\n")
    garden_operations()
    print("Testing multiple errors together...")

    try:
        garden: dict = {"Rose": 26}
        print(garden["missing_plant"])
        int("abc")
        print(f"{7 / 0}")
        open("missing.txt", "r")
    except (ValueError, ZeroDivisionError, FileNotFoundError, KeyError):
        print("Caught an error, but program continues!\n")


if __name__ == "__main__":
    test_error_types()
    print("All error types tested successfully!")
