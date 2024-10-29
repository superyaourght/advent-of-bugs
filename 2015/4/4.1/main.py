import hashlib
import sys

#using python for this challenge because i don't want to pull my hair out while using homebrew and trying to configure openssl
#correct and output is 254575
def main():
    secret_key: str = "bgvyzdsv"

    for i in range(0, sys.maxsize):
        pre_md5_hash: str = secret_key + str(i)
        md5_hash: str = hashlib.md5(pre_md5_hash.encode()).hexdigest()

        if md5_hash[:5] == "00000":
            print(f"Number found :\t\t{i}")
            print(f"Pre-hash :\t\t{pre_md5_hash}")
            print(f"md5-hash :\t\t{md5_hash}")
            break

if __name__ == "__main__":
    main()
