#!/usr/bin/env Python3

class GardenManager:
    def __init__(self, garden_name: str):
        self.garden_name = garden_name
    
    def create_garden_network(self) -> None:



class Garden_Stats(GardenManager):
    def __init__(self, garden_name: str):
        super().__init__(garden_name)
        

class Plant(GardenManager):
    def __init__(self, garden_name: str, plant_name: str,
                 plant_height: int, plant_age: int):
        super().__init__(garden_name)
        self.plant_name = plant_name
        self.plant_height = plant_height
        self.plant_age = plant_age
    
    @classmethod
    def grow(cls, plant_height) -> "Plant":
        plant_height += 1
        return cls(plant_height)
        

class FloweringPlant(Plant):
    def __init__(self, garden_name: str, plant_name: str, plant_height: int,
                 plant_age: int, flower_colour: str):
        super().__init__(garden_name, plant_name, plant_height, plant_age)
    
    @classmethod
    def bloom(cls) -> str:
        return "Blooming"

class PrizeFlower(FloweringPlant):
    def __init__(self, garden_name, plant_name, plant_height, plant_age):
        super().__init__(garden_name, plant_name, plant_height, plant_age)


def grow_plants() -> None:
    

print("=== Garden Management System Demo ===\n")

