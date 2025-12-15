#!/usr/bin/env python3

class Plant:
    def __init__(self, plant_name: str, plant_height: int, plant_age: int):
        self.plant_name = plant_name
        self.plant_height = plant_height
        self.plant_age = plant_age


class Flower(Plant):
    def __init__(self, plant_name: str, plant_height: int, plant_age: int,
                 colour: str):
        super().__init__(plant_name, plant_height, plant_age)
        self.colour = colour

    def bloom(self) -> None:
        """Prints the flower name and a blooming message
        """
        print(f"{self.plant_name.capitalize()} is blooming beautifully!")


class Tree(Plant):
    def __init__(self, plant_name: str, plant_height: int, plant_age: int,
                 diameter: int):
        super().__init__(plant_name, plant_height, plant_age)
        self.diameter = diameter

    def shade(self) -> None:
        """uses the tree's radius to work out the shade radius and print
           the size of the area that the sade covers
        """
        canopy_diameter: int = self.diameter * 20
        shade_radius: float = 3.1416 * ((canopy_diameter / 200) ** 2)
        print(f"{self.plant_name.capitalize()}", end=" ")
        print(f"provides {int(shade_radius)}", end=" ")
        print("square meters of shade")


class Vegetable(Plant):
    def __init__(self, plant_name: str, plant_height: int, plant_age: int,
                 harvest_season: str, nutritional_value: str):
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
