class Solution(object):
    def removeDuplicates(self, s):
        """
        :type s: str
        :rtype: str
        """
        
        result = []
        result.append(s[0])
        for i in range(1,len(s)):
            if result and result[-1] == s[i]:
                result.pop()
            else:
                result.append(s[i])
        return "".join(result)