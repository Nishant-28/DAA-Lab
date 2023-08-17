package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

func partition(arr []int, low, high int) int {
	pivot := arr[high]
	i := low - 1

	for j := low; j < high; j++ {
		if arr[j] <= pivot {
			i++
			arr[i], arr[j] = arr[j], arr[i]
		}
	}

	arr[i+1], arr[high] = arr[high], arr[i+1]
	return i + 1
}

func quickSort(arr []int, low, high int) {
	if low < high {
		pivotIndex := partition(arr, low, high)

		quickSort(arr, low, pivotIndex-1)
		quickSort(arr, pivotIndex+1, high)
	}
}

func readInputFile(filename string) ([]int, error) {
	content, err := ioutil.ReadFile(filename)
	if err != nil {
		return nil, err
	}

	lines := strings.Split(string(content), "\n")
	var arr []int

	for _, line := range lines {
		num, err := strconv.Atoi(line)
		if err != nil {
			continue
		}
		arr = append(arr, num)
	}

	return arr, nil
}

func writeOutputFile(filename string, arr []int) error {
	content := ""
	for _, num := range arr {
		content += fmt.Sprintf("%d\n", num)
	}

	err := ioutil.WriteFile(filename, []byte(content), 0644)
	return err
}

func main() {
	for {
		fmt.Println("MAIN MENU (QUICK SORT)")
		fmt.Println("1. Ascending Data")
		fmt.Println("2. Descending Data")
		fmt.Println("3. Random Data")
		fmt.Println("4. EXIT")
		fmt.Print("Enter option: ")

		var option int
		fmt.Scan(&option)

		if option == 4 {
			fmt.Println("Exiting...")
			break
		}

		var inputFilename, outputFilename, scenario string
		switch option {
		case 1:
			inputFilename = "inAsce.dat"
			outputFilename = "outQuickAsce.dat"
			scenario = "Best-case"
		case 2:
			inputFilename = "inDesc.dat"
			outputFilename = "outQuickDesc.dat"
			scenario = "Worst-case"
		case 3:
			inputFilename = "inRand.dat"
			outputFilename = "outQuickRand.dat"
			scenario = "Random"
		default:
			fmt.Println("Invalid option. Please choose a valid option.")
			continue
		}

		arr, err := readInputFile(inputFilename)
		if err != nil {
			fmt.Printf("Error reading input file: %v\n", err)
			continue
		}

		fmt.Printf("Before Sorting: %v\n", arr)

		quickSort(arr, 0, len(arr)-1)

		err = writeOutputFile(outputFilename, arr)
		if err != nil {
			fmt.Printf("Error writing output file: %v\n", err)
			continue
		}

		fmt.Printf("After Sorting: %v\n", arr)
		fmt.Printf("Number of Comparisons: %d\n", len(arr)-1)
		fmt.Printf("Scenario: %s partitioning\n", scenario)
	}
}
