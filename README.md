# CloudCoin-UnrealEngine-SDK
An Unreal Engine c++ class library written to provide quick access to functions that communicate with a server that has CloudCoinConsortium's [CloudService](https://github.com/CloudCoinConsortium/CloudService) web API, in order to create applications that can use CloudCoins.

## Usage
Create a BankKeys object that contains the keys to the CloudService server you wish to connect to. The BankKeys object should be initialized using its SetBankKeys function. Then create a CloudBankUtils object and initialize it by passing the BankKeys through the CloudBankUtils' SetCloudBankUtils function. Call CloudBankUtils' functions to communincate with the CloudService.
