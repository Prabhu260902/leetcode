class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        if(len(palindrome)==1):
            return ""
        else:
            l=len(palindrome)
            k=list(palindrome)
            if(l==k.count('a')):
                k[-1]='b'
                return ''.join(k)
            else:
                for i in range(l):
                    if(k[i]!='a' and i!=l//2):
                        k[i]='a'
                        break
                else:
                    if(k[-1]=='a'):
                        k[-1]='b'
                    else:
                        k[-1]='a'
                return ''.join(k)        