//
// Created by root on 23-8-22.
//

#include <iostream>
#include <cryptopp/eccrypto.h>
#include <cryptopp/osrng.h>
#include <cryptopp/hex.h>
#include <cryptopp/oids.h>

void printPrivateKey(const CryptoPP::ECDSA<CryptoPP::ECP, CryptoPP::SHA256>::PrivateKey &privateKey);

void printPublicKey(const CryptoPP::ECDSA<CryptoPP::ECP, CryptoPP::SHA256>::PublicKey &publicKey);

int main() {
    CryptoPP::AutoSeededRandomPool rng;

    // 生成ECDSA密钥对
    CryptoPP::ECDSA<CryptoPP::ECP, CryptoPP::SHA256>::PrivateKey privateKey;
    privateKey.Initialize(rng, CryptoPP::ASN1::secp256r1());

    CryptoPP::ECDSA<CryptoPP::ECP, CryptoPP::SHA256>::PublicKey publicKey;
    privateKey.MakePublicKey(publicKey);

    // 输出密钥对
    printPrivateKey(privateKey);
    printPublicKey(publicKey);

    return 0;
}

void printPrivateKey(const CryptoPP::ECDSA<CryptoPP::ECP, CryptoPP::SHA256>::PrivateKey &privateKey) {
    std::string privateKeyStr;

    CryptoPP::HexEncoder privateKeyEncoder(new CryptoPP::StringSink(privateKeyStr));
    privateKey.Save(privateKeyEncoder);
    privateKeyEncoder.MessageEnd();

    std::cout << "Private Key (hex): 0x" << privateKeyStr << std::endl;
}

void printPublicKey(const CryptoPP::ECDSA<CryptoPP::ECP, CryptoPP::SHA256>::PublicKey &publicKey) {
    std::string publicKeyStr;

    CryptoPP::HexEncoder publicKeyEncoder(new CryptoPP::StringSink(publicKeyStr));
    publicKey.Save(publicKeyEncoder);
    publicKeyEncoder.MessageEnd();

    std::cout << "Public Key (hex): 0x" << publicKeyStr << std::endl;
}

