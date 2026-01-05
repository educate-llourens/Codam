#!/usr/bin/env python3

class Plant:
    def __init__(self, plant_name: str, plant_height: int) -> None:
        self.plant_name = plant_name
        self.plant_height = plant_height

    def grow(self) -> None:
        self.plant_height += 1


class FloweringPlant(Plant):
    def __init__(self, plant_name, plant_height, colour: str):
        self.colour = colour
        super().__init__(plant_name, plant_height)


class PrizeFlower(FloweringPlant):
    def __init__(self, plant_name, plant_height, colour: str,
                 prize_points: int):
        self.prize_points = prize_points
        super().__init__(plant_name, plant_height, colour)


class GardenManager:
    def __init__(self, garden_name: str) -> None:
        self.garden_name: str = garden_name
        self.plants: list[Plant] = []
        self.list_len = len(self.plants)

    @classmethod
    def create_garden_network(cls) -> 'GardenManager':
        manager = cls('Alice')
        manager.add_plant(Plant("Oak Tree", 100))
        manager.add_plant(FloweringPlant("Rose", 25, "red"))
        manager.add_plant(PrizeFlower("Sunflower", 50, "yellow", 10))
        return manager

    def add_plant(self, plant: Plant) -> None:
        self.plant: Plant = plant
        self.plants.append(plant)
        self.list_len += 1
        print(f"Added {plant.plant_name} to {self.garden_name}'s garden")

    class GardenStats:
        def __init__(self, garden: 'GardenManager', growth: int):
            self.garden: GardenManager = garden
            self.nbr_plants: int = len(garden.plants)
        growth: int = 0
        plant_added: int = 0

        @staticmethod
        def print_stats(garden: 'GardenManager') -> None:
            i: int = 0
            print(f"=== {garden.garden_name}'s Garden Report ===")
            print("Plants in garden:")
            while i < len(garden.plants):
                plant = garden.plants[i]
                if isinstance(plant, PrizeFlower):
                    print(f"- {plant.plant_name}: "
                          f"{plant.plant_height}cm, "
                          f"{plant.colour} (blooming), "
                          f"Prize points: {plant.prize_points}")
                elif isinstance(plant, FloweringPlant):
                    print(f"- {plant.plant_name}: "
                          f"{plant.plant_height}cm, "
                          f"{plant.colour} (blooming)")
                elif isinstance(plant, Plant):
                    print(f"- {plant.plant_name}: "
                          f"{plant.plant_height}cm")
                i += 1
            print(
                f"\nPlants added: "
                f"{len(garden.plants) - garden.GardenStats.plant_added}, "
                f"Total growth: {garden.GardenStats.growth}cm")

    @staticmethod
    def growth_valid(days: int) -> bool:
        if days > 0:
            return True
        return False

    def grow(self, days: int) -> None:
        if self.growth_valid(days):
            print(f"{self.garden_name} is helping all the plants grow...")
            i: int = 0
            while i < len(self.plants):
                self.plants[i].plant_height += days
                print(f"{self.plants[i].plant_name} grew {days}cm")
                i += 1
            GardenManager.GardenStats.growth = len(self.plants) * days
        else:
            print("You entered an invalid growth parameter")


if __name__ == "__main__":
    print("=== Garden Management System Demo ===\n")
    alice = GardenManager.create_garden_network()
    print("")
    alice.grow(1)
    print("")
    alice.GardenStats.print_stats(alice)
