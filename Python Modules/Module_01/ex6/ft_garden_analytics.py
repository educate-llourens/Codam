#!/usr/bin/env python3


class Plant:
    """Class containing the name, height and age of the plant
    """
    def __init__(self, name: str, height: int, age: int):
        """Creates an instance of the Plant class (a plant).

        Args:
            name (str): Name of the plant
            height (int): Height of the plant in cm
            age (int): Age of the plant in days
        """
        self.name: str = name
        self.height: int = height
        self.age: int = age


class Flower(Plant):
    """Class that inherits from Plant

    Args:
        Plant (Parent): The parent class
    """
    def __init__(self, name: str, height: int, age: int,
                 colour: str, bloom: bool):
        """Creates an instance from the Flower class (a flower).

        Args:
            name (str): Name of the Flower
            height (int): Height of the Flower in cm
            age (int): Age of the Flower in days
            colour (str): Colour of the Flower when it blooms
            bloom (bool): If it is blooming or not
        """
        super().__init__(name, height, age)
        self.colour: str = colour
        self.bloom: bool = bloom


class PrizeFlower(Flower):
    def __init__(self, name: str, height: int, age: int,
                 colour: str, bloom: bool, points: int):
        super().__init__(name, height, age, colour, bloom)
        self.points: int = points


class GardenManager:
    def __init__(self, name: str):
        self.name: str = name
        self.gardens: list[GardenManager.Garden] = []


    class Garden:
        def __init__(self, garden_name: str):
            self.garden_name: str = garden_name
            self.plants_list: list[Plant] = []

        def add_plants(self, plant: Plant) -> None:
            self.plants_list.append(plant)


    class GardenStats:
        def __init__(self):
            self.

    @classmethod
    def create_garden_network(cls) -> list['GardenManager']:
        manager = cls("Manager")
        alice = manager.Garden("Alice's Garden")
        manager.gardens.append(alice)
        bob = manager.Garden("Bob's Garden")
        manager.gardens.append(alice)
        return manager


if __name__ == "__main__":
    print("=== Garden Management System Demo ===")
