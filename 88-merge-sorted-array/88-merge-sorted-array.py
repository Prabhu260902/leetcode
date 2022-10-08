class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        l=len(nums1)
        c=0
        for i in range(m,m+n):
            if i>=l:
                nums1.append(nums2[c])
                c+=1
            else:
                nums1[i]=nums2[c]
                c+=1
        nums1.sort()