from cs50 import get_string

i = 0
letter = 0
space = 0
sentence = 0
text = get_string("Text: ")
j = len(text)
for i in range(0, j, 1):
    if (text[i] >= 'a' and text[i] <= 'z') or (text[i] >= 'A' and text[i] <= 'Z'):
        letter = letter + 1
    if text[i] == ' ':
        space = space + 1
    if text[i] == '.' or text[i] == '!' or text[i] == '?':
        sentence = sentence + 1
words = space + 1                                 # count words
L = (100 * letter) / words                       # length of letters
s = (100 * sentence) / words                   # length of sentences
index = 0.0588 * L - 0.296 * s - 15.8
Index = round(index)
if Index < 1:
    print("Before Grade 1")
elif Index > 16:
    print("Grade 16+")
else:
    print("Grade", Index)