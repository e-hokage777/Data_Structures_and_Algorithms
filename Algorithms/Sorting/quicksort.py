## chooses last element as the pivot
def quicksort_partition(array, low, high):
    pivot = array[high]

    j = low
    for i in range(low, high):
        if array[i] <= pivot:
            ## swap
            array[i], array[j] = array[j], array[i]

            ## increment j (greater pointer)
            j+=1
    
    ## swapping pivot with last greater integer found
    array[high], array[j] = array[j], array[high]

    return j

def quicksort(array, low, high):
    if high <= low:
        return
    ## partition array
    pivot_index = quicksort_partition(array, low, high)

    ## quicksort left
    quicksort(array, low, pivot_index-1)

    ## quicksort right
    quicksort(array, pivot_index+1, high)


if __name__ == "__main__":
    array = list(map(int,input("Array (space separated) => ").split()))
    print(f"Unsorted Array {array}")
    quicksort(array, 0, len(array)-1)
    print(f"Sorted Array {array}")
