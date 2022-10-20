class Solution:
    def intToRoman(self, num: int) -> str:
        n=num
        p=[]
        while n > 0:
            if n >= 1000:
                t = n // 1000
                p.append(t * 'M')
                n-= t * 1000
                              
            elif n>= 500:
                
                if n >= 900:
                    p.append('CM')
                    n -= 900
                else:
                    p.append('D')
                    n -= 500
                
            elif n >= 100:
                t = n // 100
                
                if t== 4:
                    p.append('CD')
                    n-= 400
                else:
                    p.append(t * 'C')
                    n -= t * 100
                
            elif n>= 50:
                
                if n >= 90:
                    p.append('XC')
                    n -= 90
                else:
                    p.append('L')
                    n -= 50
                
            elif n>= 10:
                t = n // 10
                
                if t== 4:
                    p.append('XL')
                    n -= 40
                else:
                    p.append(t* 'X')
                    n -= t * 10
                
            elif n >= 5:
                
                if n >= 9:
                    p.append('IX')
                    n -= 9
                else:
                    p.append('V')
                    n -= 5
                
            elif n>= 1:
                t = n // 1
                
                if t== 4:
                    p.append('IV')
                    n -= 4
                else:
                    p.append(t * 'I')
                    n -= t * 1
        return ''.join(p)