Nome: Leoardo Luís Müller

Problema 748 Leetcode:

Given a string licensePlate and an array of strings words, find the shortest completing word in words.
A completing word is a word that contains all the letters in licensePlate. 
Ignore numbers and spaces in licensePlate, and treat letters as case insensitive. 
If a letter appears 
more than once in licensePlate, then it must appear in the word the same number of times or more.
For example, if licensePlate = "aBc 12c", then it contains letters 'a', 'b' (ignoring case), and 'c' twice.
Possible completing words are "abccdef", "caaacab", and "cbca".

Return the shortest completing word in words. It is guaranteed an answer exists. 
If there are multiple shortest completing words, return the first one that occurs in words.

Três casos em que o problema funciona:

licensePlate[] = {"1s3 pst"}, *words[] = {"step","steps","stripe","stepple"};
Retorna: steps

licensePlate2[] = {"1s3 456"}, *words2[] = {"looks","pest","stew","show"};
Retorna: pest

licensePlate3[] = {"aBc 12c"}, *words3[] = {"abccdef", "caaacab", "cbca"};
Retorna: cbca
