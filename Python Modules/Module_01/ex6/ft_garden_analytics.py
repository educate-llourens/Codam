#!/usr/bin/env python3

class Plant:
    """
    Characteristics of a regular plant
    """
    def __init__(self, plant_name: str, plant_height: int) -> None:
        """
        Initialises the Plant class

        Args:
            plant_name (str): The name of the plant
            plant_height (int): The height of the plant
        """
        self.plant_name: str = plant_name
        self.plant_height: int = plant_height


class FloweringPlant(Plant):
    """
    Characteristics of the FloweringPlant which inherits from Plant

    Args:
        Plant (): The regular plant class that FloweringPlant depends on
    """
    def __init__(self, plant_name, plant_height, colour: str):
        """
        Initialises the FloweringPlant class

        Args:
            plant_name (_type_): Name of the plant
            plant_height (_type_): Height of the plant
            colour (str): Colour of the flower when it blooms
        """
        self.colour: str = colour
        super().__init__(plant_name, plant_height)


class PrizeFlower(FloweringPlant):
    """
    Characteristics of the PrizeFlower

    Args:
        FloweringPlant (Plant): The FloweringPlant class that PrizeFlower
        depends on
    """
    def __init__(self, plant_name: str, plant_height: int, colour: str,
                 prize_points: int):
        """
        Initialises the PrizeFlower class

        Args:
            plant_name (str): Name of the plant
            plant_height (int): Height of the plant
            colour (str): Colour of the flower when it blooms
            prize_points (int): The number of points awarded to it
        """
        self.prize_points: int = prize_points
        super().__init__(plant_name, plant_height, colour)


class Garden:
    """
    Creates and manages a garden with various plant types
    """
    def __init__(self, garden_name: str) -> None:
        """
        Initialises the Garden class

        Args:
            garden_name (str): Name of the garden
        """
        self.garden_name: str = garden_name
        self.plants: list[Plant] = []
        self.list_len = len(self.plants)
        self.stats = Garden.GardenStats(self)
        self.growth_check: bool = True

    def add_plant(self, plant: Plant) -> None:
        """
        Adds a plant to the garden

        Args:
            plant (Plant): The plant to be added to the garden
        """
        self.plant: Plant = plant
        self.plants.append(plant)
        self.list_len += 1
        print(f"Added {plant.plant_name} to {self.garden_name}'s garden")

    class GardenStats:
        """
        A class to manage the statistics for the garden
        """
        def __init__(self, garden: 'Garden'):
            """
            Initialses the GardenStats class

            Args:
                garden (Garden): The garden that we need to calculate
                and print the stats for.
            """
            self.growth: int = 0
            self.garden: Garden = garden
            self.nbr_plants: int = len(garden.plants)
            self.plant_added: int = 0
            self.garden_score: int = 0

        @staticmethod
        def calculate_plant_types(garden: 'Garden') -> list[int]:
            """
            Calculates the number of each type of plant in the garden
            Args:
                garden (Garden): The garden we need to do the calculation on

            Returns:
                list[int]: Returns a list containing the totals for each
                plant type
            """
            i: int = 0
            regular: int = 0
            flowering: int = 0
            prize: int = 0
            while i < len(garden.plants):
                plant = garden.plants[i]
                if isinstance(plant, PrizeFlower):
                    prize += 1
                elif isinstance(plant, FloweringPlant):
                    flowering += 1
                elif isinstance(plant, Plant):
                    regular += 1
                i += 1
            type_list: list[int] = [regular, flowering, prize]
            return type_list

        @staticmethod
        def print_stats(garden: 'Garden') -> None:
            """
            Prints the statistics for the garden

            Args:
                garden (Garden): The garden we need to print he statistics for
            """
            i: int = 0
            print(f"=== {garden.garden_name}'s Garden Report ===")
            print("Plants in garden:")
            while i < len(garden.plants):
                plant = garden.plants[i]
                if isinstance(plant, PrizeFlower):
                    print(f"- {plant.plant_name}: "
                          f"{plant.plant_height}cm, "
                          f"{plant.colour} flowers (blooming), "
                          f"Prize points: {plant.prize_points}")
                elif isinstance(plant, FloweringPlant):
                    print(f"- {plant.plant_name}: "
                          f"{plant.plant_height}cm, "
                          f"{plant.colour} flowers (blooming)")
                elif isinstance(plant, Plant):
                    print(f"- {plant.plant_name}: "
                          f"{plant.plant_height}cm")
                i += 1
            print(
                f"\nPlants added: "
                f"{len(garden.plants) - garden.stats.plant_added}, "
                f"Total growth: {garden.stats.growth}cm")
            types_list: list[int] = garden.GardenStats.\
                calculate_plant_types(garden)
            print(f"Plant types: {types_list[0]} regular, "
                  f"{types_list[1]} flowering, {types_list[2]} prize flowers")

    @staticmethod
    def growth_valid(days: int) -> bool:
        """
        Checks if the growth input is a valid input

        Args:
            days (int): The number of days the plant should grow

        Returns:
            bool: Returns True if the input is valid or false if it is not.
        """
        if days > 0:
            return True
        return False

    def grow(self, days: int) -> None:
        """
        It calculates the growth for all the plants in the garden based on the
        number of days to grow at 1cm per day.

        Args:
            days (int): The number of days to grow
        """
        if self.growth_valid(days):
            print(f"{self.garden_name} is helping all the plants grow...")
            i: int = 0
            while i < len(self.plants):
                self.plants[i].plant_height += days
                print(f"{self.plants[i].plant_name} grew {days}cm")
                i += 1
            self.stats.growth = len(self.plants) * days
        else:
            print("You entered an invalid growth parameter")
            self.growth_check = False

    @classmethod
    def add_score(cls, score: int) -> None:
        """
        Adds the garden score dor the garden

        Args:
            score (int): The score for the garden
        """
        cls.GardenStats.garden_score = score


class GardenManager:
    def __init__(self, manager_name: str) -> None:
        """
        Initialises the GardenManager class

        Args:
            manager_name (str): The name of the garden manager
        """
        self.manager_name: str = manager_name
    gardens: list[Garden] = []

    @classmethod
    def add_garden(cls, garden_name: str) -> list[Garden]:
        """
        Adds a garden to the list of gardens that the manager manages

        Args:
            garden_name (str): Name of the garden to be added to the list

        Returns:
            list[Garden]: Returns the appended list of gardens
        """
        cls.gardens.append(Garden(garden_name))
        return cls.gardens

    @classmethod
    def create_garden_network(cls) -> 'GardenManager':
        """
        Creates and populates the network of gardens that the manager manages

        Returns:
            GardenManager: Returns an instance of GardenManager
        """
        alice.add_garden("Alice")
        alice.add_garden("Bob")
        for i in range(0, len(alice.gardens)):
            if alice.gardens[i].garden_name == "Alice":
                alice.gardens[i].add_plant(Plant("Oak Tree", 100))
                alice.gardens[i].add_plant(FloweringPlant("Rose", 25, "red"))
                alice.gardens[i].add_plant(PrizeFlower("Sunflower", 50,
                                                       "yellow", 10))

    def print_manager_stats(self) -> None:
        """
        Prints the statistics for the manager
        """
        i: int = 0
        for i in range(0, len(self.gardens)):
            if self.gardens[i].growth_check is False:
                break
        print(f"\nHeight validation test: {self.gardens[i].growth_check}")
        print("Garden scores -", end=" ")
        i = 0
        gardens_len: int = len(self.gardens)
        for i in range(0, gardens_len):
            if i == gardens_len - 1:
                print(f"{self.gardens[i].garden_name}: "
                      f"{self.gardens[i].stats.garden_score}")
                break
            print(f"{self.gardens[i].garden_name}: "
                  f"{self.gardens[i].stats.garden_score},", end=" ")
        print(f"Total gardens managed: {len(self.gardens)}")


if __name__ == "__main__":
    i: int = 0
    alice_index: int = 0
    print("=== Garden Management System Demo ===")
    alice: GardenManager = GardenManager("Alice")
    print("")
    alice.create_garden_network()
    print("")
    alice.gardens[alice_index].grow(1)
    print("")
    alice.gardens[alice_index].GardenStats\
        .print_stats(alice.gardens[alice_index])
    alice.gardens[alice_index].stats.garden_score = 218
    for i in range(0, len(alice.gardens)):
        if alice.gardens[i].garden_name == "Bob":
            bob_index = i
    alice.gardens[bob_index].stats.garden_score = 92
    alice.print_manager_stats()
