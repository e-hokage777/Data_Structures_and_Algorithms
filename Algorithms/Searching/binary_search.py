def binary_search(l, data):
    left = 0
    right = len(l) - 1

    while left <= right:
        middle = (left+right)//2

        ## return if found
        middle_val = l[middle]
        if middle_val == data: return middle
        elif data < middle_val: right = middle - 1
        elif data > middle_val: left = middle + 1

    return -1


if __name__ == "__main__":
    array = list(map(int,input("Sorted Array (space separated) => ").split()))
    value = int(input("Value to find: "))
    idx = binary_search(array, value)
    print(f"Index of {value}: {idx}")
