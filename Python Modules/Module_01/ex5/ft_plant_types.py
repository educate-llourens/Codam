#!/usr/bin/env python3

class Plant:
    """
        Contains the characteristics of a plant
    """
    def __init__(self, plant_name: str, plant_height: int, plant_age: int):
        """
            Initialises the Plant class

        Args:
            plant_name (str): Name of the plant
            plant_height (int): Height of the plant
            plant_age (int): Age of the plant
        """
        self.plant_name = plant_name
        self.plant_height = plant_height
        self.plant_age = plant_age


class Flower(Plant):
    """
        Contains the charectistics of a flower and inherits from the
        Plant class

    Args:
        Plant (): The class Flower inherits from
    """
    def __init__(self, plant_name: str, plant_height: int, plant_age: int,
                 colour: str):
        """
        Initialises the Flower class

        Args:
            plant_name (str): Name of the flower
            plant_height (int): height of the flower
            plant_age (int): Age of the flower
            colour (str): Colour of the flower when it blooms
        """
        super().__init__(plant_name, plant_height, plant_age)
        self.colour = colour

    def bloom(self) -> None:
        """
        Prints the flower name and a blooming message
        """
        print(f"{self.plant_name.capitalize()} is blooming beautifully!")


class Tree(Plant):
    """
    Contains the characteristics of a tree

    Args:
        Plant (): The class that Tree inherits from
    """
    def __init__(self, plant_name: str, plant_height: int, plant_age: int,
                 diameter: int):
        """
        Initialises the Tree class

        Args:
            plant_name (str): Name of the tree
            plant_height (int): Height of the tree
            plant_age (int): Age of the tree
            diameter (int): Diameter of the tree
        """
        super().__init__(plant_name, plant_height, plant_age)
        self.diameter = diameter

    def shade(self) -> None:
        """
        Uses the tree's radius to work out the shade radius and print
            the size of the area that the sade covers
        """
        canopy_diameter: int = self.diameter * 20
        shade_radius: float = 3.1416 * ((canopy_diameter / 200) ** 2)
        print(f"{self.plant_name.capitalize()}", end=" ")
        print(f"provides {int(shade_radius)}", end=" ")
        print("square meters of shade")


class Vegetable(Plant):
    """
    Contains characteristics of the Vegetable plant

    Args:
        Plant (): The class that Vegetable inherits from
    """
    def __init__(self, plant_name: str, plant_height: int, plant_age: int,
                 harvest_season: str, nutritional_value: str):
        """
        Initialises the Vegetable class

        Args:
            plant_name (str): Name of the plant
            plant_height (int): Height of the plant
            plant_age (int): Age of the plant
            harvest_season (str): The best season to harvest the vegetable
            nutritional_value (str): The nutritional value of the vegetable
        """
        super().__init__(plant_name, plant_height, plant_age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value

    def nutrition(self) -> None:
        """prints the name of the vegetable and the nutrient it is highest in
        """
        print(f"{self.plant_name} is high in", end=" ")
        print(f"{self.nutritional_value}")


def print_flower(flower: Flower) -> None:
    """Prints the information for the flower and calls the bloom function

    Args:
        flower (Flower): The flower that we need to print the information for
    """
    print(f"{flower.plant_name.capitalize()}", end=" ")
    print(f"({flower.__class__.__name__.capitalize()}):", end=" ")
    print(f"{flower.plant_height}cm, {flower.plant_age} days,", end=" ")
    print(f"{flower.colour} colour")
    flower.bloom()


def print_tree(tree: Tree) -> None:
    """Prints the information for the tree and the area of shade it produces
       and calls the shade function

    Args:
        tree (Tree): The tree that we need to print the information for
    """
    print(f"{tree.plant_name.capitalize()}", end=" ")
    print(f"({tree.__class__.__name__.capitalize()}):", end=" ")
    print(f"{tree.plant_height}cm, {tree.plant_age} days,", end=" ")
    print(f"{tree.diameter}cm diameter")
    tree.shade()


def print_vegetable(veg: Vegetable) -> None:
    """Prints the information for the vegetable and calls the
       nutritional value function

    Args:
        veg (Vegetable): the vegetable that we need to print the
        information for
    """
    print(f"{veg.plant_name.capitalize()}", end=" ")
    print(f"({veg.__class__.__name__.capitalize()}):", end=" ")
    print(f"{veg.plant_height}cm, {veg.plant_age} days,", end=" ")
    print(f"{veg.harvest_season} harvest")
    print(f"{veg.plant_name.capitalize()} is rich in", end=" ")
    print(f"{veg.nutritional_value}")


rose: Flower = Flower("rose", 25, 30, "red")
sunflower: Flower = Flower("sunflower", 100, 60, "yellow")
oak: Tree = Tree("oak", 500, 1825, 50)
Elm: Tree = Tree("elm", 400, 1500, 70)
tomato: Vegetable = Vegetable("tomato", 80, 90, "summer", "Vitamin C")
orange: Vegetable = Vegetable("orange", 5, 20, "winter", "Vitamin C")

print("=== Garden Plant Types ===\n")
print_flower(rose)
print("")
print_tree(oak)
print("")
print_vegetable(tomato)
