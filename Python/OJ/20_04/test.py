def entityParser(text: str) -> str:
    d = {"&quot": "\"",
         "&apos": "\'",
         "&amp": "&",
         "&gt": ">",
         "&lt": "<",
         "&frasl": "/"}
    start = 0
    len_ = len(text)
    i = 0
    while i < len_-1:
        remain = len_ - i-1
        lw = 6 if remain >= 6 else remain
        if text[i] == '&':
            start = i
            temp = text[i:i+lw]
            for j in range(lw):
                if temp[:j] in d.keys():
                    c = d[temp[:j]]
                    text = text[:start]+c+text[start+j+1:]
                    len_ = len(text)
                    break

    return text


print(entityParser("&frasl is"))
