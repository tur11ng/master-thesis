from Crypto.PublicKey import RSA
from Crypto.Random import get_random_bytes
from Crypto.Cipher import AES, PKCS1_OAEP
from Crypto.Util.Padding import pad, unpad

from time import process_time


data = "CRYPTOGRAPHY".encode("utf-8")

key = RSA.generate(2048)
private_key = key
public_key = key.publickey()

t1_start = process_time()

enc_rsa = PKCS1_OAEP.new(public_key)
dec_rsa = PKCS1_OAEP.new(private_key)
enc_data = enc_rsa.encrypt(data)
dec_data = dec_rsa.decrypt(enc_data)

t1_stop = process_time()

assert(dec_data == data)
print("Elapsed time for RSA encryption and decryption in milliseconds:",
                                         "{:.2f}".format((t1_stop-t1_start) * 1000))

key = get_random_bytes(16)

t1_start = process_time()

cipher_aes = AES.new(key, AES.MODE_ECB)
enc_data = cipher_aes.encrypt(pad(data, 32))
dec_data = unpad(cipher_aes.decrypt(enc_data), 32)

t1_stop = process_time()

assert(dec_data == data)
print("Elapsed time for AES encryption and decryption in milliseconds:",
                                         "{:.2f}".format((t1_stop-t1_start) * 1000))