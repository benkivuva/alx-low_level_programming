#!/usr/bin/python3

"""
Island Perimeter
"""


def island_perimeter(grid):
    """Function that returns the perimeter of the island described in grid"""

    rows = len(grid)
    cols = len(grid[0])

    def is_land(row, col):
        return 0 <= row < rows and 0 <= col < cols and grid[row][col] == 1

    perimeter = 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:  # If it's part of the island
                perimeter += 4  # Add 4 to the perimeter for each land cell

                # Check the neighboring cells to deduct from the perimeter
                if is_land(i - 1, j):
                    perimeter -= 1
                if is_land(i + 1, j):
                    perimeter -= 1
                if is_land(i, j - 1):
                    perimeter -= 1
                if is_land(i, j + 1):
                    perimeter -= 1

    return perimeter
