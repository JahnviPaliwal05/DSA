def generate_subsets(nums):
    result = []

    def helper(index, path):
        if index == len(nums):
            result.append(path[:])
            return

        # Exclude
        helper(index + 1, path)

        # Include
        path.append(nums[index])
        helper(index + 1, path)
        path.pop()

    helper(0, [])
    return result

setm = [2,3,41,43]
pm = generate_subsets(setm)
print('All the susets are:',pm)

