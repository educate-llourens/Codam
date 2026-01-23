#!/usr/bin/env python3


class Plant:
    """Class containing the name, height and age of the plant
    """
    def __init__(self, name: str, height: int):
        """Creates an instance of the Plant class (a plant).

        Args:
            name (str): Name of the plant
            height (int): Height of the plant in cm
            age (int): Age of the plant in days
        """
        self.name: str = name
        self.height: int = height


class Flower(Plant):
    """Class that inherits from Plant

    Args:
        Plant (Parent): The parent class
    """
    def __init__(self, name: str, height: int,
                 colour: str, bloom: bool):
        """Creates an instance from the Flower class (a flower).

        Args:
            name (str): Name of the Flower
            height (int): Height of the Flower in cm
            age (int): Age of the Flower in days
            colour (str): Colour of the Flower when it blooms
            bloom (bool): If it is blooming or not
        """
        super().__init__(name, height)
        self.colour: str = colour
        self.bloom: bool = bloom


class PrizeFlower(Flower):
    def __init__(self, name: str, height: int,
                 colour: str, bloom: bool, points: int):
        super().__init__(name, height, colour, bloom)
        self.points: int = points


class GardenManager:
    def __init__(self, name: str):
        self.name: str = name
        self.gardens: list[GardenManager.Garden] = []
        self.manager_stats: GardenManager.GardenStats = self.GardenStats(self)

    class Garden:
        def __init__(self, garden_name: str, manager: 'GardenManager'):
            self.garden_name: str = garden_name
            self.manager = manager
            self.plants_list: list[Plant] = []

        def add_plants(self, plant: Plant) -> None:
            self.plant = plant
            self.plants_list.append(self.plant)
            self.manager.manager_stats.plants_added += 1
            print(f"Added {self.plant.name} to "
                  f"{self.garden_name}")

    class GardenStats:
        def __init__(self, manager: 'GardenManager'):
            self.manager = manager
            self.plants_added = 0

    @classmethod
    def create_garden_network(cls) -> 'GardenManager':
        manager = cls("Manager")
        alice = manager.Garden("Alice's garden", manager)
        manager.gardens.append(alice)
        bob = manager.Garden("Bob's garden", manager)
        manager.gardens.append(bob)
        return manager


if __name__ == "__main__":
    print("=== Garden Management System Demo ===\n")

    # Plants
    oak_tree = Plant("Oak Tree", 100)
    rose = Flower("Rose", 25, "red", True)
    sunflower = PrizeFlower("Sunflower", 50, "yellow", True, 10)

    # Add plants
    nursery = GardenManager.create_garden_network()
    nursery.gardens[0].add_plants(oak_tree)
    nursery.gardens[0].add_plants(rose)
    nursery.gardens[0].add_plants(sunflower)

    # Grow plants
