# 编译条件
CC	=	gcc
CFLAGS	=	-g -Wall 

# Objs
# all:	string_replace match_string represent_number_string
# all:	permutation_ofStrings
# all:	numberOf_one
# all:	Atio Itoa
# all:	numberOf_one
# all:	digitSequence
# all:	sortArrayForMinNumber
# all:	translation_numberTostring
# all:	firstNotRepeatingChar
# all:	firstCharacterInStream
# all:	reverseSentence
all:	leftRotateString

# Objs 函数编译
string_replace:	string_replace.o 
	$(CC) $^ -o $@
match_string: match_string.o 
	$(CC) $^ -o $@
represent_number_string: represent_number_string.o 
	$(CC) $^ -o $@
permutation_ofStrings:	permutation_ofStrings.o
	$(CC) $^ -o $@
numberOf_one:	numberOf_one.o 
	$(CC) $^ -o $@
Atio:	Atio.o 
	$(CC) $^ -o $@
Itoa:	Itoa.o
	$(CC) $^ -o $@
digitSequence:	digitSequence.o 
	$(CC) $^ -o $@ -lm
sortArrayForMinNumber:	sortArrayForMinNumber.o 
	$(CC) $^ -o $@ -lm
translation_numberTostring:	translation_numberTostring.o 
	$(CC) $^ -o $@ -lm
firstNotRepeatingChar:	firstNotRepeatingChar.o
	$(CC) $^ -o $@ 
firstCharacterInStream:	firstCharacterInStream.o
	$(CC) $^ -o $@ 
reverseSentence:	reverseSentence.o 
	$(CC) $^ -o $@ 

leftRotateString:	leftRotateString.o 
	$(CC) $^ -o $@ 

# .o 文件的编译
string_replace.o:	string_replace.c 
	$(CC) $(CFLAGS) -c $< -o $@

match_string.o: match_string.c
	$(CC) $(CFLAGS) -c $< -o $@

represent_number_string.o: represent_number_string.c
	$(CC) $(CFLAGS) -c $< -o $@
	
permutation_ofStrings.o: permutation_ofStrings.c
	$(CC) $(CFLAGS) -c $< -o $@

numberOf_one.o: numberOf_one.c
	$(CC) $(CFLAGS) -c $< -o $@

Atio.o: Atio.c
	$(CC) $(CFLAGS) -c $< -o $@

Itoa.o: Itoa.c
	$(CC) $(CFLAGS) -c $< -o $@

digitSequence.o: digitSequence.c
	$(CC) $(CFLAGS) -c $< -o $@

sortArrayForMinNumber.o: sortArrayForMinNumber.c
	$(CC) $(CFLAGS) -c $< -o $@

translation_numberTostring.o: translation_numberTostring.c
	$(CC) $(CFLAGS) -c $< -o $@

firstNotRepeatingChar.o: firstNotRepeatingChar.c
	$(CC) $(CFLAGS) -c $< -o $@

firstCharacterInStream.o: firstCharacterInStream.c
	$(CC) $(CFLAGS) -c $< -o $@

reverseSentence.o: reverseSentence.c
	$(CC) $(CFLAGS) -c $< -o $@

leftRotateString.o: leftRotateString.c
	$(CC) $(CFLAGS) -c $< -o $@

#clean
clean:	
	@echo "cleaning project"
	-rm string_replace match_string represent_number_string
	-rm permutation_ofStrings numberOf_one Atio Itoa
	-rm numberOf_one digitSequence sortArrayForMinNumber
	-rm translation_numberTostring firstNotRepeatingChar
	-rm firstCharacterInStream	reverseSentence	leftRotateString
	-rm *.o 
	@echo "cleaning complie"
.PHONY:	clean