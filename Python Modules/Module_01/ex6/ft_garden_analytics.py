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
            self.points: int = 0

        def add_plants(self, plant: Plant) -> None:
            self.plant = plant
            self.plants_list.append(self.plant)
            self.manager.manager_stats.plants_added += 1
            if plant.height > 0:
                self.manager.manager_stats.height_validation = True
            print(f"Added {self.plant.name} to "
                  f"{self.garden_name}'s garden")

        def grow(self) -> None:
            i: int = 0
            nbr_plants: int = len(self.plants_list)
            print(f"\n{self.garden_name} is helping all the plants grow...")
            for i in range(0, nbr_plants):
                self.plants_list[i].height += 1
                print(f"{self.plants_list[i].name} grew 1cm")
            self.manager.manager_stats.total_growth = nbr_plants

    class GardenStats:
        def __init__(self, manager: 'GardenManager'):
            self.manager = manager
            self.plants_added = 0
            self.total_growth = 0
            self.height_validation = False
            self.nbr_gardens = 0

        def count_plant_types(self, manager: 'GardenManager') -> list[int]:
            nbr_prize_flower: int = 0
            nbr_flower: int = 0
            nbr_plant: int = 0
            count_plant_types: list[int] = []
            self.manager = manager
            for garden in self.manager.gardens:
                for plant in self.manager.gardens[0].plants_list:
                    if isinstance(plant, PrizeFlower):
                        nbr_prize_flower += 1
                    elif isinstance(plant, Flower):
                        nbr_flower += 1
                    else:
                        nbr_plant += 1
            count_plant_types = [nbr_plant, nbr_flower, nbr_prize_flower]
            return count_plant_types

        def count_gardens(self, manager: 'GardenManager') -> None:
            for garden in manager.gardens:
                manager.manager_stats.nbr_gardens += 1

    @classmethod
    def create_garden_network(cls) -> 'GardenManager':
        manager = cls("Manager")
        alice = manager.Garden("Alice", manager)
        manager.gardens.append(alice)
        bob = manager.Garden("Bob", manager)
        manager.gardens.append(bob)
        return manager


def add_plants(manager: GardenManager, plants: list[Plant]) -> None:
    manager.gardens[0].add_plants(oak_tree)
    manager.gardens[0].add_plants(rose)
    manager.gardens[0].add_plants(sunflower)


def print_plant(plant: Plant) -> None:
    print(f"- {plant.name}: {plant.height}cm")


def print_flower(flower: Flower) -> None:
    if flower.bloom:
        print(f"- {flower.name}: {flower.height}cm"
              f", {flower.colour} flowers"
              f" (blooming)")
    else:
        print(f"- {flower.name}: {flower.height}cm"
              f", {flower.colour} flowers")


def print_prize_flower(prize_flower: PrizeFlower) -> None:
    if prize_flower.bloom:
        print(f"- {prize_flower.name}: {prize_flower.height}cm"
              f", {prize_flower.colour} flowers"
              f" (blooming), Prize points: {prize_flower.points}")
    else:
        print(f"- {prize_flower.name}: {prize_flower.height}cm"
              f", {prize_flower.colour} flowers")


def garden_report(garden: GardenManager.Garden) -> None:
    plant_types: list[int] = []
    print(f"=== {garden.garden_name}'s Garden report ===\n")
    print("Plants in garden:")
    for plant in garden.plants_list:
        if isinstance(plant, PrizeFlower):
            print_prize_flower(plant)
        elif isinstance(plant, Flower):
            print_flower(plant)
        else:
            print_plant(plant)
    print(f"\nPlants added: {garden.manager.manager_stats.plants_added}, "
          f"Total growth: {garden.manager.manager_stats.total_growth}")
    plant_types = garden.manager.manager_stats.\
        count_plant_types(garden.manager)
    print(f"Plant types: {plant_types[0]} "
          f"regular, {plant_types[1]} flowering, "
          f"{plant_types[2]} prize flowers")


def manager_summary(manager: GardenManager) -> None:
    print(f"\nHeight validation test: "
          f"{manager.manager_stats.height_validation}")
    print(f"Garden scores - {manager.gardens[0].garden_name}: "
          f"{manager.gardens[0].points}, "
          f"{manager.gardens[1].garden_name}: "
          f"{manager.gardens[1].points}")
    manager.manager_stats.count_gardens(manager)
    print(f"Total gardens managed: {manager.manager_stats.nbr_gardens}")


if __name__ == "__main__":
    print("=== Garden Management System Demo ===\n")

    nursery = GardenManager.create_garden_network()

    # Add Plants
    oak_tree = Plant("Oak Tree", 100)
    rose = Flower("Rose", 25, "red", True)
    sunflower = PrizeFlower("Sunflower", 50, "yellow", True, 10)
    plants: list[Plant] = [oak_tree, rose, sunflower]
    add_plants(nursery, plants)

    # Grow plants
    nursery.gardens[0].grow()

    # Alice garden report
    print("")
    garden_report(nursery.gardens[0])

    # Manager summary
    nursery.gardens[0].points = 218
    nursery.gardens[1].points = 92
    manager_summary(nursery)
