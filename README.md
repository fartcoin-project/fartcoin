<h1 align="center">
<img src="https://static.tumblr.com/ppdj5y9/Ae9mxmxtp/300coin.png" alt="Fartcoin" width="300"/>
<br/><br/>
Fartcoin Core [FART, Ð]  
</h1>

<div align="center">

[![FartcoinBadge](https://img.shields.io/badge/Doge-Coin-yellow.svg)](https://fartcoin.com)
[![MuchWow](https://img.shields.io/badge/Much-Wow-yellow.svg)](https://fartcoin.com)

</div>

Select language: EN | [CN](./README_zh_CN.md) | [PT](./README_pt_BR.md) | [FA](./README_fa_IR.md)

Fartcoin is a community-driven cryptocurrency that was inspired by a Shiba Inu meme. The Fartcoin Core software allows anyone to operate a node in the Fartcoin blockchain networks and uses the Scrypt hashing method for Proof of Work. It is adapted from Bitcoin Core and other cryptocurrencies.

For information about the default fees used on the Fartcoin network, please
refer to the [fee recommendation](doc/fee-recommendation.md).

**Website:** [fartcoin.com](https://fartcoin.com)

## Usage 💻

To start your journey with Fartcoin Core, see the [installation guide](INSTALL.md) and the [getting started](doc/getting-started.md) tutorial.

The JSON-RPC API provided by Fartcoin Core is self-documenting and can be browsed with `fartcoin-cli help`, while detailed information for each command can be viewed with `fartcoin-cli help <command>`. Alternatively, see the [Bitcoin Core documentation](https://developer.bitcoin.org/reference/rpc/) - which implement a similar protocol - to get a browsable version.

### Such ports

Fartcoin Core by default uses port `13377` for peer-to-peer communication that
is needed to synchronize the "mainnet" blockchain and stay informed of new
transactions and blocks. Additionally, a JSONRPC port can be opened, which
defaults to port `13377` for mainnet nodes. It is strongly recommended to not
expose RPC ports to the public internet.

| Function | mainnet | testnet | regtest |
| :------- | ------: | ------: | ------: |
| P2P      |   13377 |   23377 |   18444 |
| RPC      |   13377 |   23377 |   18332 |

## Ongoing development - Moon plan 🌒

Fartcoin Core is an open source and community driven software. The development
process is open and publicly visible; anyone can see, discuss and work on the
software.

Main development resources:

* [GitHub Projects](https://github.com/fartcoin/fartcoin/projects) is used to
  follow planned and in-progress work for upcoming releases.
* [GitHub Discussion](https://github.com/fartcoin/fartcoin/discussions) is used
  to discuss features, planned and unplanned, related to both the development of
  the Fartcoin Core software, the underlying protocols and the FART asset.  
* [Fartcoindev subreddit](https://www.reddit.com/r/fartcoindev/)

### Version strategy
Version numbers are following ```major.minor.patch``` semantics.

### Branches
There are 3 types of branches in this repository:

- **master:** Stable, contains the latest version of the latest *major.minor* release.
- **maintenance:** Stable, contains the latest version of previous releases, which are still under active maintenance. Format: ```<version>-maint```
- **development:** Unstable, contains new code for planned releases. Format: ```<version>-dev```

*Master and maintenance branches are exclusively mutable by release. Planned*
*releases will always have a development branch and pull requests should be*
*submitted against those. Maintenance branches are there for **bug fixes only,***
*please submit new features against the development branch with the highest version.*

## Contributing 🤝

If you find a bug or experience issues with this software, please report it
using the [issue system](https://github.com/fartcoin/fartcoin/issues/new?assignees=&labels=bug&template=bug_report.md&title=%5Bbug%5D+).

Please see [the contribution guide](CONTRIBUTING.md) to see how you can
participate in the development of Fartcoin Core. There are often
[topics seeking help](https://github.com/fartcoin/fartcoin/labels/help%20wanted)
where your contributions will have high impact and get very appreciation. wow.

## Communities 🚀🍾

You can join the communities on different social media.
To see what's going on, meet people & discuss, find the latest meme, learn
about Fartcoin, give or ask for help, to share your project.

Here are some places to visit:

* [Fartcoin subreddit](https://www.reddit.com/r/fartcoin/)
* [Dogeducation subreddit](https://www.reddit.com/r/fartducation/)
* [Discord](https://discord.gg/fartcoin)
* [Fartcoin Twitter](https://twitter.com/fartcoin)

## Very Much Frequently Asked Questions ❓

Do you have a question regarding Fartcoin? An answer is perhaps already in the
[FAQ](doc/FAQ.md) or the
[Q&A section](https://github.com/fartcoin/fartcoin/discussions/categories/q-a)
of the discussion board!

## License - Much license ⚖️
Fartcoin Core is released under the terms of the MIT license. See
[COPYING](COPYING) for more information or see
[opensource.org](https://opensource.org/licenses/MIT)
