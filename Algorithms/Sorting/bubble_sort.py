def bubble_sort(l):
    n = len(l)
    swapped = False
    for i in range(n-1):
        for j in range(n-1-i):
            if l[j] > l[j+1]:
                temp = l[j+1]
                l[j+1] = l[j]
                l[j] = temp
                swapped = True

        if not swapped:
            return
        elif i > n/2:
            return


if __name__ == "__main__":
    array = list(map(int,input("Array (space separated) => ").split()))
    print(f"Unsorted Array {array}")
    bubble_sort(array)
    print(f"Sorted Array {array}")
