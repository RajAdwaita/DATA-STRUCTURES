
class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        
        l=len(words)
        d={}
        
        for i in words[0]:
            d[i]=d.get(i,0)+1
        for i in words:
            for j in d:
                d[j]=min(d[j],i.count(j))
        final=[]
        
        for i in d:
            if d[i]>0:
                for j in range(d[i]):
                    final.append(i)
        return final

        