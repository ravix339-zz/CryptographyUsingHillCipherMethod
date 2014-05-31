Cryptography
============

Cryptography encoder and decoder using the Hill Cipher Method. 

The Programmers:
  Ravi Sinha, Ajay Kumar, Neha Shah

Overview of the Hill Cipher Method:
  The Hill cipher method involves converting a string of text into a series of numbers (in this case we used the
  ASCII value of the text). For example, A = 1, B = 2, C =3... Z = 26. After converting the string into numbers, we
  then take the numbers and divide it into triplets. Then we generate a random key matrix (3x3) and multiply it by the
  3x1 triplets to receive a 3x1 encrypted series of numbers. To decode, we took the ecrypted sequence, multiplied it by
  the inverse of the key and converted the now decrypted ASCII values to their character form.
