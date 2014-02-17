class Solution:
    # @param s, a string
    # @return an integer

    def lengthOfLastWord(self, s):
        if s == None:
            return 0
        else:
            s = s.split()
            if len(s) == 0:
                return 0
            return len(s[-1])
