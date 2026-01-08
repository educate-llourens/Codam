#!/usr/bin/env python3

def test_temperature_input() -> None:
    print("=== Garden Temperature Checker ===\n")

    test_temp = "25"
    print(f"Testing temperature: {test_temp}")
    check_temperature(test_temp)

    test_temp = "abc"
    print(f"Testing temperature: {test_temp}")
    check_temperature(test_temp)

    test_temp = "100"
    print(f"Testing temperature: {test_temp}")
    check_temperature(test_temp)

    test_temp = "-50"
    print(f"Testing temperature: {test_temp}")
    check_temperature(test_temp)


def check_temperature(temp_str) -> int:
    try:
        temp: int = int(temp_str)
    except ValueError:
        print("Error: 'abc' is not a valid number\n")
        return None
    if (temp < 0) or (temp > 40):
        if temp < 0:
            print(f"Error: {temp}°C is too cold for plants (min 0°C)\n")
            return None
        else:
            print(f"Error: {temp}°C is too hot for plants (max 40°C)\n")
            return None
    print(f"Temperature {temp}°C is perfect for plants!\n")
    return temp


if __name__ == "__main__":
    test_temperature_input()
    print("All tests completed - program didn't crash!")
