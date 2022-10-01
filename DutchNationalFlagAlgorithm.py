def dutchsort(arr, n):
    low = 0
    high = n - 1
    mid = 0
    while mid <= high:
        if arr[mid] == 0:
            arr[low], arr[mid] = arr[mid], arr[low]
            low = low + 1
            mid = mid + 1
        elif arr[mid] == 1:
            mid = mid + 1
        else:
            arr[mid], arr[high] = arr[high], arr[mid]
            high = high - 1
    return arr


# Driver Program
arr = [0, 1, 2, 0, 1, 2]
n = len(arr)
arr = dutchsort(arr, n)
print(arr)
