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
        super().__init__(plant_name, plant_height, colour)


class GardenManager:
    def __init__(self, garden_name: str) -> None:
        self.garden_name: str = garden_name
        self.plants: list[Plant] = []

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
        print(f"Added {plant.plant_name} to {self.garden_name}'s garden")

    class GardenStats:
        def __init__(self, garden: 'GardenManager', growth: int):
            self.garden: GardenManager = garden
            self.nbr_plants: int = len(garden.plants)
            self.growth: int = 0

        @staticmethod
        def print_stats(garden: 'GardenManager') -> None:
            print(f"=== {garden.garden_name}'s Garden Report ===")

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
            GardenManager.GardenStats(self, len(self.plants) * days)
        else:
            print("You entered an invalid growth parameter")


def 

if __name__ == "__main__":
    print("=== Garden Management System Demo ===\n")
    alice = GardenManager.create_garden_network()
    print("")
    alice.grow(1)
    print("")
    
    alice.GardenStats.print_stats(alice)
