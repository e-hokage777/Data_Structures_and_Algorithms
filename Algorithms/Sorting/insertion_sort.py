def insertion_sort(l):
    for i in range(len(l)):
        j = i-1
        while(j >= 0 and l[i] < l[j]):
            temp = l[i]
            l[i] = l[j]
            l[j] = temp

            j-=1
            i-=1


if __name__ == "__main__":
    array = list(map(int,input("Array (space separated) => ").split()))
    print(f"Unsorted Array {array}")
    insertion_sort(array)
    print(f"Sorted Array {array}")
