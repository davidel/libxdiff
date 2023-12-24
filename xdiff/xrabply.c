/*    Copyright 2023 Davide Libenzi
 * 
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 * 
 *        http://www.apache.org/licenses/LICENSE-2.0
 * 
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 * 
 */
#if defined(XRABPLY_TYPE64)

#if !defined(XV64)
#define XV64(v) ((xply_word) v ## ULL)
#endif

#define XRAB_ROOTPOLY XV64(0x36f7381af4d70d33)

#define XRAB_SHIFT 53
#define XRAB_WNDSIZE 20

typedef unsigned XRABPLY_TYPE64 xply_word;

static const xply_word T[256] = {
	XV64(0x0), XV64(0x36f7381af4d70d33), XV64(0x5b19482f1d791755), XV64(0x6dee7035e9ae1a66),
	XV64(0x80c5a844ce252399), XV64(0xb632905e3af22eaa), XV64(0xdbdce06bd35c34cc), XV64(0xed2bd871278b39ff),
	XV64(0x18b50899c4a4732), XV64(0x377c6893689d4a01), XV64(0x5a9218a681335067), XV64(0x6c6520bc75e45d54),
	XV64(0x814ef8cd526f64ab), XV64(0xb7b9c0d7a6b86998), XV64(0xda57b0e24f1673fe), XV64(0xeca088f8bbc17ecd),
	XV64(0x316a11338948e64), XV64(0x35e19909cc438357), XV64(0x580fe93c25ed9931), XV64(0x6ef8d126d13a9402),
	XV64(0x83d30957f6b1adfd), XV64(0xb524314d0266a0ce), XV64(0xd8ca4178ebc8baa8), XV64(0xee3d79621f1fb79b),
	XV64(0x29df19aa4dec956), XV64(0x346ac9805009c465), XV64(0x5984b9b5b9a7de03), XV64(0x6f7381af4d70d330),
	XV64(0x825859de6afbeacf), XV64(0xb4af61c49e2ce7fc), XV64(0xd94111f17782fd9a), XV64(0xefb629eb8355f0a9),
	XV64(0x62d422671291cc8), XV64(0x30da7a3c85fe11fb), XV64(0x5d340a096c500b9d), XV64(0x6bc33213988706ae),
	XV64(0x86e8ea62bf0c3f51), XV64(0xb01fd2784bdb3262), XV64(0xddf1a24da2752804), XV64(0xeb069a5756a22537),
	XV64(0x7a612afed635bfa), XV64(0x31512ab519b456c9), XV64(0x5cbf5a80f01a4caf), XV64(0x6a48629a04cd419c),
	XV64(0x8763baeb23467863), XV64(0xb19482f1d7917550), XV64(0xdc7af2c43e3f6f36), XV64(0xea8dcadecae86205),
	XV64(0x53be33549bd92ac), XV64(0x33ccdb2fbd6a9f9f), XV64(0x5e22ab1a54c485f9), XV64(0x68d59300a01388ca),
	XV64(0x85fe4b718798b135), XV64(0xb309736b734fbc06), XV64(0xdee7035e9ae1a660), XV64(0xe8103b446e36ab53),
	XV64(0x4b0b3bcd5f7d59e), XV64(0x32478ba62120d8ad), XV64(0x5fa9fb93c88ec2cb), XV64(0x695ec3893c59cff8),
	XV64(0x84751bf81bd2f607), XV64(0xb28223e2ef05fb34), XV64(0xdf6c53d706abe152), XV64(0xe99b6bcdf27cec61),
	XV64(0xc5a844ce2523990), XV64(0x3aadbc56168534a3), XV64(0x5743cc63ff2b2ec5), XV64(0x61b4f4790bfc23f6),
	XV64(0x8c9f2c082c771a09), XV64(0xba681412d8a0173a), XV64(0xd7866427310e0d5c), XV64(0xe1715c3dc5d9006f),
	XV64(0xdd1d4c57e187ea2), XV64(0x3b26ecdf8acf7391), XV64(0x56c89cea636169f7), XV64(0x603fa4f097b664c4),
	XV64(0x8d147c81b03d5d3b), XV64(0xbbe3449b44ea5008), XV64(0xd60d34aead444a6e), XV64(0xe0fa0cb45993475d),
	XV64(0xf4c255fdac6b7f4), XV64(0x39bb1d452e11bac7), XV64(0x54556d70c7bfa0a1), XV64(0x62a2556a3368ad92),
	XV64(0x8f898d1b14e3946d), XV64(0xb97eb501e034995e), XV64(0xd490c534099a8338), XV64(0xe267fd2efd4d8e0b),
	XV64(0xec775d6468cf0c6), XV64(0x38304dccb25bfdf5), XV64(0x55de3df95bf5e793), XV64(0x632905e3af22eaa0),
	XV64(0x8e02dd9288a9d35f), XV64(0xb8f5e5887c7ede6c), XV64(0xd51b95bd95d0c40a), XV64(0xe3ecada76107c939),
	XV64(0xa77c66a937b2558), XV64(0x3c80fe7067ac286b), XV64(0x516e8e458e02320d), XV64(0x6799b65f7ad53f3e),
	XV64(0x8ab26e2e5d5e06c1), XV64(0xbc455634a9890bf2), XV64(0xd1ab260140271194), XV64(0xe75c1e1bb4f01ca7),
	XV64(0xbfc96e30f31626a), XV64(0x3d0baef9fbe66f59), XV64(0x50e5decc1248753f), XV64(0x6612e6d6e69f780c),
	XV64(0x8b393ea7c11441f3), XV64(0xbdce06bd35c34cc0), XV64(0xd0207688dc6d56a6), XV64(0xe6d74e9228ba5b95),
	XV64(0x9616779abefab3c), XV64(0x3f965f635f38a60f), XV64(0x52782f56b696bc69), XV64(0x648f174c4241b15a),
	XV64(0x89a4cf3d65ca88a5), XV64(0xbf53f727911d8596), XV64(0xd2bd871278b39ff0), XV64(0xe44abf088c6492c3),
	XV64(0x8ea37f037a5ec0e), XV64(0x3e1d0feac372e13d), XV64(0x53f37fdf2adcfb5b), XV64(0x650447c5de0bf668),
	XV64(0x882f9fb4f980cf97), XV64(0xbed8a7ae0d57c2a4), XV64(0xd336d79be4f9d8c2), XV64(0xe5c1ef81102ed5f1),
	XV64(0x18b50899c4a47320), XV64(0x2e42308330737e13), XV64(0x43ac40b6d9dd6475), XV64(0x755b78ac2d0a6946),
	XV64(0x9870a0dd0a8150b9), XV64(0xae8798c7fe565d8a), XV64(0xc369e8f217f847ec), XV64(0xf59ed0e8e32f4adf),
	XV64(0x193e581058ee3412), XV64(0x2fc9600aac393921), XV64(0x4227103f45972347), XV64(0x74d02825b1402e74),
	XV64(0x99fbf05496cb178b), XV64(0xaf0cc84e621c1ab8), XV64(0xc2e2b87b8bb200de), XV64(0xf41580617f650ded),
	XV64(0x1ba3a98afc30fd44), XV64(0x2d54919008e7f077), XV64(0x40bae1a5e149ea11), XV64(0x764dd9bf159ee722),
	XV64(0x9b6601ce3215dedd), XV64(0xad9139d4c6c2d3ee), XV64(0xc07f49e12f6cc988), XV64(0xf68871fbdbbbc4bb),
	XV64(0x1a28f903607aba76), XV64(0x2cdfc11994adb745), XV64(0x4131b12c7d03ad23), XV64(0x77c6893689d4a010),
	XV64(0x9aed5147ae5f99ef), XV64(0xac1a695d5a8894dc), XV64(0xc1f41968b3268eba), XV64(0xf703217247f18389),
	XV64(0x1e984abfb58d6fe8), XV64(0x286f72a5415a62db), XV64(0x45810290a8f478bd), XV64(0x73763a8a5c23758e),
	XV64(0x9e5de2fb7ba84c71), XV64(0xa8aadae18f7f4142), XV64(0xc544aad466d15b24), XV64(0xf3b392ce92065617),
	XV64(0x1f131a3629c728da), XV64(0x29e4222cdd1025e9), XV64(0x440a521934be3f8f), XV64(0x72fd6a03c06932bc),
	XV64(0x9fd6b272e7e20b43), XV64(0xa9218a6813350670), XV64(0xc4cffa5dfa9b1c16), XV64(0xf238c2470e4c1125),
	XV64(0x1d8eebac8d19e18c), XV64(0x2b79d3b679ceecbf), XV64(0x4697a3839060f6d9), XV64(0x70609b9964b7fbea),
	XV64(0x9d4b43e8433cc215), XV64(0xabbc7bf2b7ebcf26), XV64(0xc6520bc75e45d540), XV64(0xf0a533ddaa92d873),
	XV64(0x1c05bb251153a6be), XV64(0x2af2833fe584ab8d), XV64(0x471cf30a0c2ab1eb), XV64(0x71ebcb10f8fdbcd8),
	XV64(0x9cc01361df768527), XV64(0xaa372b7b2ba18814), XV64(0xc7d95b4ec20f9272), XV64(0xf12e635436d89f41),
	XV64(0x14ef8cd526f64ab0), XV64(0x2218b4cfd2214783), XV64(0x4ff6c4fa3b8f5de5), XV64(0x7901fce0cf5850d6),
	XV64(0x942a2491e8d36929), XV64(0xa2dd1c8b1c04641a), XV64(0xcf336cbef5aa7e7c), XV64(0xf9c454a4017d734f),
	XV64(0x1564dc5cbabc0d82), XV64(0x2393e4464e6b00b1), XV64(0x4e7d9473a7c51ad7), XV64(0x788aac69531217e4),
	XV64(0x95a1741874992e1b), XV64(0xa3564c02804e2328), XV64(0xceb83c3769e0394e), XV64(0xf84f042d9d37347d),
	XV64(0x17f92dc61e62c4d4), XV64(0x210e15dceab5c9e7), XV64(0x4ce065e9031bd381), XV64(0x7a175df3f7ccdeb2),
	XV64(0x973c8582d047e74d), XV64(0xa1cbbd982490ea7e), XV64(0xcc25cdadcd3ef018), XV64(0xfad2f5b739e9fd2b),
	XV64(0x16727d4f822883e6), XV64(0x2085455576ff8ed5), XV64(0x4d6b35609f5194b3), XV64(0x7b9c0d7a6b869980),
	XV64(0x96b7d50b4c0da07f), XV64(0xa040ed11b8daad4c), XV64(0xcdae9d245174b72a), XV64(0xfb59a53ea5a3ba19),
	XV64(0x12c2cef357df5678), XV64(0x2435f6e9a3085b4b), XV64(0x49db86dc4aa6412d), XV64(0x7f2cbec6be714c1e),
	XV64(0x920766b799fa75e1), XV64(0xa4f05ead6d2d78d2), XV64(0xc91e2e98848362b4), XV64(0xffe9168270546f87),
	XV64(0x13499e7acb95114a), XV64(0x25bea6603f421c79), XV64(0x4850d655d6ec061f), XV64(0x7ea7ee4f223b0b2c),
	XV64(0x938c363e05b032d3), XV64(0xa57b0e24f1673fe0), XV64(0xc8957e1118c92586), XV64(0xfe62460bec1e28b5),
	XV64(0x11d46fe06f4bd81c), XV64(0x272357fa9b9cd52f), XV64(0x4acd27cf7232cf49), XV64(0x7c3a1fd586e5c27a),
	XV64(0x9111c7a4a16efb85), XV64(0xa7e6ffbe55b9f6b6), XV64(0xca088f8bbc17ecd0), XV64(0xfcffb79148c0e1e3),
	XV64(0x105f3f69f3019f2e), XV64(0x26a8077307d6921d), XV64(0x4b467746ee78887b), XV64(0x7db14f5c1aaf8548),
	XV64(0x909a972d3d24bcb7), XV64(0xa66daf37c9f3b184), XV64(0xcb83df02205dabe2), XV64(0xfd74e718d48aa6d1)
};

static const xply_word U[256] = {
	XV64(0x0), XV64(0x1c3eb44b122426b2), XV64(0xe8a508cd09f4057), XV64(0x12b4e4c7c2bb66e5),
	XV64(0x1d14a119a13e80ae), XV64(0x12a1552b31aa61c), XV64(0x139ef19571a1c0f9), XV64(0xfa045de6385e64b),
	XV64(0xcde7a29b6aa0c6f), XV64(0x10e0ce62a48e2add), XV64(0x2542aa566354c38), XV64(0x1e6a9eee74116a8a),
	XV64(0x11cadb3017948cc1), XV64(0xdf46f7b05b0aa73), XV64(0x1f408bbcc70bcc96), XV64(0x37e3ff7d52fea24),
	XV64(0x19bcf4536d5418de), XV64(0x58240187f703e6c), XV64(0x1736a4dfbdcb5889), XV64(0xb081094afef7e3b),
	XV64(0x4a8554acc6a9870), XV64(0x1896e101de4ebec2), XV64(0xa2205c61cf5d827), XV64(0x161cb18d0ed1fe95),
	XV64(0x15628e7adbfe14b1), XV64(0x95c3a31c9da3203), XV64(0x1be8def60b6154e6), XV64(0x7d66abd19457254),
	XV64(0x8762f637ac0941f), XV64(0x14489b2868e4b2ad), XV64(0x6fc7fefaa5fd448), XV64(0x1ac2cba4b87bf2fa),
	XV64(0x58ed0bc2e7f3c8f), XV64(0x19b064f73c5b1a3d), XV64(0xb048030fee07cd8), XV64(0x173a347becc45a6a),
	XV64(0x189a71a58f41bc21), XV64(0x4a4c5ee9d659a93), XV64(0x161021295fdefc76), XV64(0xa2e95624dfadac4),
	XV64(0x950aa9598d530e0), XV64(0x156e1ede8af11652), XV64(0x7dafa19484a70b7), XV64(0x1be44e525a6e5605),
	XV64(0x14440b8c39ebb04e), XV64(0x87abfc72bcf96fc), XV64(0x1ace5b00e974f019), XV64(0x6f0ef4bfb50d6ab),
	XV64(0x1c3224ef432b2451), XV64(0xc90a4510f02e3), XV64(0x12b8746393b46406), XV64(0xe86c028819042b4),
	XV64(0x12685f6e215a4ff), XV64(0x1d1831bdf031824d), XV64(0xfacd57a328ae4a8), XV64(0x1392613120aec21a),
	XV64(0x10ec5ec6f581283e), XV64(0xcd2ea8de7a50e8c), XV64(0x1e660e4a251e6869), XV64(0x258ba01373a4edb),
	XV64(0xdf8ffdf54bfa890), XV64(0x11c64b94469b8e22), XV64(0x372af538420e8c7), XV64(0x1f4c1b189604ce75),
	XV64(0xb1da1785cfe791e), XV64(0x172315334eda5fac), XV64(0x597f1f48c613949), XV64(0x19a945bf9e451ffb),
	XV64(0x16090061fdc0f9b0), XV64(0xa37b42aefe4df02), XV64(0x188350ed2d5fb9e7), XV64(0x4bde4a63f7b9f55),
	XV64(0x7c3db51ea547571), XV64(0x1bfd6f1af87053c3), XV64(0x9498bdd3acb3526), XV64(0x15773f9628ef1394),
	XV64(0x1ad77a484b6af5df), XV64(0x6e9ce03594ed36d), XV64(0x145d2ac49bf5b588), XV64(0x8639e8f89d1933a),
	XV64(0x12a1552b31aa61c0), XV64(0xe9fe160238e4772), XV64(0x1c2b05a7e1352197), XV64(0x15b1ecf3110725),
	XV64(0xfb5f4329094e16e), XV64(0x138b407982b0c7dc), XV64(0x13fa4be400ba139), XV64(0x1d0110f5522f878b),
	XV64(0x1e7f2f0287006daf), XV64(0x2419b4995244b1d), XV64(0x10f57f8e579f2df8), XV64(0xccbcbc545bb0b4a),
	XV64(0x36b8e1b263eed01), XV64(0x1f553a50341acbb3), XV64(0xde1de97f6a1ad56), XV64(0x11df6adce4858be4),
	XV64(0xe9371c472814591), XV64(0x12adc58f60a56323), XV64(0x192148a21e05c6), XV64(0x1c279503b03a2374),
	XV64(0x1387d0ddd3bfc53f), XV64(0xfb96496c19be38d), XV64(0x1d0d805103208568), XV64(0x133341a1104a3da),
	XV64(0x24d0bedc42b49fe), XV64(0x1e73bfa6d60f6f4c), XV64(0xcc75b6114b409a9), XV64(0x10f9ef2a06902f1b),
	XV64(0x1f59aaf46515c950), XV64(0x3671ebf7731efe2), XV64(0x11d3fa78b58a8907), XV64(0xded4e33a7aeafb5),
	XV64(0x172f85971fd55d4f), XV64(0xb1131dc0df17bfd), XV64(0x19a5d51bcf4a1d18), XV64(0x59b6150dd6e3baa),
	XV64(0xa3b248ebeebdde1), XV64(0x160590c5accffb53), XV64(0x4b174026e749db6), XV64(0x188fc0497c50bb04),
	XV64(0x1bf1ffbea97f5120), XV64(0x7cf4bf5bb5b7792), XV64(0x157baf3279e01177), XV64(0x9451b796bc437c5),
	XV64(0x6e55ea70841d18e), XV64(0x1adbeaec1a65f73c), XV64(0x86f0e2bd8de91d9), XV64(0x1451ba60cafab76b),
	XV64(0x163b42f0b9fcf23c), XV64(0xa05f6bbabd8d48e), XV64(0x18b1127c6963b26b), XV64(0x48fa6377b4794d9),
	XV64(0xb2fe3e918c27292), XV64(0x171157a20ae65420), XV64(0x5a5b365c85d32c5), XV64(0x199b072eda791477),
	XV64(0x1ae538d90f56fe53), XV64(0x6db8c921d72d8e1), XV64(0x146f6855dfc9be04), XV64(0x851dc1ecded98b6),
	XV64(0x7f199c0ae687efd), XV64(0x1bcf2d8bbc4c584f), XV64(0x97bc94c7ef73eaa), XV64(0x15457d076cd31818),
	XV64(0xf87b6a3d4a8eae2), XV64(0x13b902e8c68ccc50), XV64(0x10de62f0437aab5), XV64(0x1d33526416138c07),
	XV64(0x129317ba75966a4c), XV64(0xeada3f167b24cfe), XV64(0x1c194736a5092a1b), XV64(0x27f37db72d0ca9),
	XV64(0x359cc8a6202e68d), XV64(0x1f6778c17026c03f), XV64(0xdd39c06b29da6da), XV64(0x11ed284da0b98068),
	XV64(0x1e4d6d93c33c6623), XV64(0x273d9d8d1184091), XV64(0x10c73d1f13a32674), XV64(0xcf98954018700c6),
	XV64(0x13b5924c9783ceb3), XV64(0xf8b260785a7e801), XV64(0x1d3fc2c0471c8ee4), XV64(0x101768b5538a856),
	XV64(0xea1335536bd4e1d), XV64(0x129f871e249968af), XV64(0x2b63d9e6220e4a), XV64(0x1c15d792f40628f8),
	XV64(0x1f6be8652129c2dc), XV64(0x3555c2e330de46e), XV64(0x11e1b8e9f1b6828b), XV64(0xddf0ca2e392a439),
	XV64(0x27f497c80174272), XV64(0x1e41fd37923364c0), XV64(0xcf519f050880225), XV64(0x10cbadbb42ac2497),
	XV64(0xa09661ffad7d66d), XV64(0x1637d254e8f3f0df), XV64(0x48336932a48963a), XV64(0x18bd82d8386cb088),
	XV64(0x171dc7065be956c3), XV64(0xb23734d49cd7071), XV64(0x1997978a8b761694), XV64(0x5a923c199523026),
	XV64(0x6d71c364c7dda02), XV64(0x1ae9a87d5e59fcb0), XV64(0x85d4cba9ce29a55), XV64(0x1463f8f18ec6bce7),
	XV64(0x1bc3bd2fed435aac), XV64(0x7fd0964ff677c1e), XV64(0x1549eda33ddc1afb), XV64(0x97759e82ff83c49),
	XV64(0x1d26e388e5028b22), XV64(0x11857c3f726ad90), XV64(0x13acb304359dcb75), XV64(0xf92074f27b9edc7),
	XV64(0x324291443c0b8c), XV64(0x1c0cf6da56182d3e), XV64(0xeb8121d94a34bdb), XV64(0x1286a65686876d69),
	XV64(0x11f899a153a8874d), XV64(0xdc62dea418ca1ff), XV64(0x1f72c92d8337c71a), XV64(0x34c7d669113e1a8),
	XV64(0xcec38b8f29607e3), XV64(0x10d28cf3e0b22151), XV64(0x2666834220947b4), XV64(0x1e58dc7f302d6106),
	XV64(0x49a17db885693fc), XV64(0x18a4a3909a72b54e), XV64(0xa10475758c9d3ab), XV64(0x162ef31c4aedf519),
	XV64(0x198eb6c229681352), XV64(0x5b002893b4c35e0), XV64(0x1704e64ef9f75305), XV64(0xb3a5205ebd375b7),
	XV64(0x8446df23efc9f93), XV64(0x147ad9b92cd8b921), XV64(0x6ce3d7eee63dfc4), XV64(0x1af08935fc47f976),
	XV64(0x1550cceb9fc21f3d), XV64(0x96e78a08de6398f), XV64(0x1bda9c674f5d5f6a), XV64(0x7e4282c5d7979d8),
	XV64(0x18a83334cb7db7ad), XV64(0x496877fd959911f), XV64(0x162263b81be2f7fa), XV64(0xa1cd7f309c6d148),
	XV64(0x5bc922d6a433703), XV64(0x19822666786711b1), XV64(0xb36c2a1badc7754), XV64(0x170876eaa8f851e6),
	XV64(0x1476491d7dd7bbc2), XV64(0x848fd566ff39d70), XV64(0x1afc1991ad48fb95), XV64(0x6c2addabf6cdd27),
	XV64(0x962e804dce93b6c), XV64(0x155c5c4fcecd1dde), XV64(0x7e8b8880c767b3b), XV64(0x1bd60cc31e525d89),
	XV64(0x114c767a629af73), XV64(0x1d2a732cb40d89c1), XV64(0xf9e97eb76b6ef24), XV64(0x13a023a06492c996),
	XV64(0x1c00667e07172fdd), XV64(0x3ed2351533096f), XV64(0x128a36f2d7886f8a), XV64(0xeb482b9c5ac4938),
	XV64(0xdcabd4e1083a31c), XV64(0x11f4090502a785ae), XV64(0x340edc2c01ce34b), XV64(0x1f7e5989d238c5f9),
	XV64(0x10de1c57b1bd23b2), XV64(0xce0a81ca3990500), XV64(0x1e544cdb612263e5), XV64(0x26af89073064557)
};

#endif /* if defined(XRABPLY_TYPE64) */

#if defined(XRABPLY_TYPE32)

#if !defined(XV32)
#define XV32(v) ((xply_word) v ## ULL)
#endif

#define XRAB_ROOTPOLY XV32(0xabd1f37b)

#define XRAB_SHIFT 23
#define XRAB_WNDSIZE 20

typedef unsigned XRABPLY_TYPE32 xply_word;

static const xply_word T[256] = {
	XV32(0x0), XV32(0xabd1f37b), XV32(0x57a3e6f6), XV32(0xfc72158d),
	XV32(0x4963e97), XV32(0xaf47cdec), XV32(0x5335d861), XV32(0xf8e42b1a),
	XV32(0x92c7d2e), XV32(0xa2fd8e55), XV32(0x5e8f9bd8), XV32(0xf55e68a3),
	XV32(0xdba43b9), XV32(0xa66bb0c2), XV32(0x5a19a54f), XV32(0xf1c85634),
	XV32(0x1258fa5c), XV32(0xb9890927), XV32(0x45fb1caa), XV32(0xee2aefd1),
	XV32(0x16cec4cb), XV32(0xbd1f37b0), XV32(0x416d223d), XV32(0xeabcd146),
	XV32(0x1b748772), XV32(0xb0a57409), XV32(0x4cd76184), XV32(0xe70692ff),
	XV32(0x1fe2b9e5), XV32(0xb4334a9e), XV32(0x48415f13), XV32(0xe390ac68),
	XV32(0x24b1f4b8), XV32(0x8f6007c3), XV32(0x7312124e), XV32(0xd8c3e135),
	XV32(0x2027ca2f), XV32(0x8bf63954), XV32(0x77842cd9), XV32(0xdc55dfa2),
	XV32(0x2d9d8996), XV32(0x864c7aed), XV32(0x7a3e6f60), XV32(0xd1ef9c1b),
	XV32(0x290bb701), XV32(0x82da447a), XV32(0x7ea851f7), XV32(0xd579a28c),
	XV32(0x36e90ee4), XV32(0x9d38fd9f), XV32(0x614ae812), XV32(0xca9b1b69),
	XV32(0x327f3073), XV32(0x99aec308), XV32(0x65dcd685), XV32(0xce0d25fe),
	XV32(0x3fc573ca), XV32(0x941480b1), XV32(0x6866953c), XV32(0xc3b76647),
	XV32(0x3b534d5d), XV32(0x9082be26), XV32(0x6cf0abab), XV32(0xc72158d0),
	XV32(0x4963e970), XV32(0xe2b21a0b), XV32(0x1ec00f86), XV32(0xb511fcfd),
	XV32(0x4df5d7e7), XV32(0xe624249c), XV32(0x1a563111), XV32(0xb187c26a),
	XV32(0x404f945e), XV32(0xeb9e6725), XV32(0x17ec72a8), XV32(0xbc3d81d3),
	XV32(0x44d9aac9), XV32(0xef0859b2), XV32(0x137a4c3f), XV32(0xb8abbf44),
	XV32(0x5b3b132c), XV32(0xf0eae057), XV32(0xc98f5da), XV32(0xa74906a1),
	XV32(0x5fad2dbb), XV32(0xf47cdec0), XV32(0x80ecb4d), XV32(0xa3df3836),
	XV32(0x52176e02), XV32(0xf9c69d79), XV32(0x5b488f4), XV32(0xae657b8f),
	XV32(0x56815095), XV32(0xfd50a3ee), XV32(0x122b663), XV32(0xaaf34518),
	XV32(0x6dd21dc8), XV32(0xc603eeb3), XV32(0x3a71fb3e), XV32(0x91a00845),
	XV32(0x6944235f), XV32(0xc295d024), XV32(0x3ee7c5a9), XV32(0x953636d2),
	XV32(0x64fe60e6), XV32(0xcf2f939d), XV32(0x335d8610), XV32(0x988c756b),
	XV32(0x60685e71), XV32(0xcbb9ad0a), XV32(0x37cbb887), XV32(0x9c1a4bfc),
	XV32(0x7f8ae794), XV32(0xd45b14ef), XV32(0x28290162), XV32(0x83f8f219),
	XV32(0x7b1cd903), XV32(0xd0cd2a78), XV32(0x2cbf3ff5), XV32(0x876ecc8e),
	XV32(0x76a69aba), XV32(0xdd7769c1), XV32(0x21057c4c), XV32(0x8ad48f37),
	XV32(0x7230a42d), XV32(0xd9e15756), XV32(0x259342db), XV32(0x8e42b1a0),
	XV32(0x3916219b), XV32(0x92c7d2e0), XV32(0x6eb5c76d), XV32(0xc5643416),
	XV32(0x3d801f0c), XV32(0x9651ec77), XV32(0x6a23f9fa), XV32(0xc1f20a81),
	XV32(0x303a5cb5), XV32(0x9bebafce), XV32(0x6799ba43), XV32(0xcc484938),
	XV32(0x34ac6222), XV32(0x9f7d9159), XV32(0x630f84d4), XV32(0xc8de77af),
	XV32(0x2b4edbc7), XV32(0x809f28bc), XV32(0x7ced3d31), XV32(0xd73cce4a),
	XV32(0x2fd8e550), XV32(0x8409162b), XV32(0x787b03a6), XV32(0xd3aaf0dd),
	XV32(0x2262a6e9), XV32(0x89b35592), XV32(0x75c1401f), XV32(0xde10b364),
	XV32(0x26f4987e), XV32(0x8d256b05), XV32(0x71577e88), XV32(0xda868df3),
	XV32(0x1da7d523), XV32(0xb6762658), XV32(0x4a0433d5), XV32(0xe1d5c0ae),
	XV32(0x1931ebb4), XV32(0xb2e018cf), XV32(0x4e920d42), XV32(0xe543fe39),
	XV32(0x148ba80d), XV32(0xbf5a5b76), XV32(0x43284efb), XV32(0xe8f9bd80),
	XV32(0x101d969a), XV32(0xbbcc65e1), XV32(0x47be706c), XV32(0xec6f8317),
	XV32(0xfff2f7f), XV32(0xa42edc04), XV32(0x585cc989), XV32(0xf38d3af2),
	XV32(0xb6911e8), XV32(0xa0b8e293), XV32(0x5ccaf71e), XV32(0xf71b0465),
	XV32(0x6d35251), XV32(0xad02a12a), XV32(0x5170b4a7), XV32(0xfaa147dc),
	XV32(0x2456cc6), XV32(0xa9949fbd), XV32(0x55e68a30), XV32(0xfe37794b),
	XV32(0x7075c8eb), XV32(0xdba43b90), XV32(0x27d62e1d), XV32(0x8c07dd66),
	XV32(0x74e3f67c), XV32(0xdf320507), XV32(0x2340108a), XV32(0x8891e3f1),
	XV32(0x7959b5c5), XV32(0xd28846be), XV32(0x2efa5333), XV32(0x852ba048),
	XV32(0x7dcf8b52), XV32(0xd61e7829), XV32(0x2a6c6da4), XV32(0x81bd9edf),
	XV32(0x622d32b7), XV32(0xc9fcc1cc), XV32(0x358ed441), XV32(0x9e5f273a),
	XV32(0x66bb0c20), XV32(0xcd6aff5b), XV32(0x3118ead6), XV32(0x9ac919ad),
	XV32(0x6b014f99), XV32(0xc0d0bce2), XV32(0x3ca2a96f), XV32(0x97735a14),
	XV32(0x6f97710e), XV32(0xc4468275), XV32(0x383497f8), XV32(0x93e56483),
	XV32(0x54c43c53), XV32(0xff15cf28), XV32(0x367daa5), XV32(0xa8b629de),
	XV32(0x505202c4), XV32(0xfb83f1bf), XV32(0x7f1e432), XV32(0xac201749),
	XV32(0x5de8417d), XV32(0xf639b206), XV32(0xa4ba78b), XV32(0xa19a54f0),
	XV32(0x597e7fea), XV32(0xf2af8c91), XV32(0xedd991c), XV32(0xa50c6a67),
	XV32(0x469cc60f), XV32(0xed4d3574), XV32(0x113f20f9), XV32(0xbaeed382),
	XV32(0x420af898), XV32(0xe9db0be3), XV32(0x15a91e6e), XV32(0xbe78ed15),
	XV32(0x4fb0bb21), XV32(0xe461485a), XV32(0x18135dd7), XV32(0xb3c2aeac),
	XV32(0x4b2685b6), XV32(0xe0f776cd), XV32(0x1c856340), XV32(0xb754903b)
};

static const xply_word U[256] = {
	XV32(0x0), XV32(0x5ce33923), XV32(0x1217813d), XV32(0x4ef4b81e),
	XV32(0x242f027a), XV32(0x78cc3b59), XV32(0x36388347), XV32(0x6adbba64),
	XV32(0x485e04f4), XV32(0x14bd3dd7), XV32(0x5a4985c9), XV32(0x6aabcea),
	XV32(0x6c71068e), XV32(0x30923fad), XV32(0x7e6687b3), XV32(0x2285be90),
	XV32(0x3b6dfa93), XV32(0x678ec3b0), XV32(0x297a7bae), XV32(0x7599428d),
	XV32(0x1f42f8e9), XV32(0x43a1c1ca), XV32(0xd5579d4), XV32(0x51b640f7),
	XV32(0x7333fe67), XV32(0x2fd0c744), XV32(0x61247f5a), XV32(0x3dc74679),
	XV32(0x571cfc1d), XV32(0xbffc53e), XV32(0x450b7d20), XV32(0x19e84403),
	XV32(0x76dbf526), XV32(0x2a38cc05), XV32(0x64cc741b), XV32(0x382f4d38),
	XV32(0x52f4f75c), XV32(0xe17ce7f), XV32(0x40e37661), XV32(0x1c004f42),
	XV32(0x3e85f1d2), XV32(0x6266c8f1), XV32(0x2c9270ef), XV32(0x707149cc),
	XV32(0x1aaaf3a8), XV32(0x4649ca8b), XV32(0x8bd7295), XV32(0x545e4bb6),
	XV32(0x4db60fb5), XV32(0x11553696), XV32(0x5fa18e88), XV32(0x342b7ab),
	XV32(0x69990dcf), XV32(0x357a34ec), XV32(0x7b8e8cf2), XV32(0x276db5d1),
	XV32(0x5e80b41), XV32(0x590b3262), XV32(0x17ff8a7c), XV32(0x4b1cb35f),
	XV32(0x21c7093b), XV32(0x7d243018), XV32(0x33d08806), XV32(0x6f33b125),
	XV32(0x46661937), XV32(0x1a852014), XV32(0x5471980a), XV32(0x892a129),
	XV32(0x62491b4d), XV32(0x3eaa226e), XV32(0x705e9a70), XV32(0x2cbda353),
	XV32(0xe381dc3), XV32(0x52db24e0), XV32(0x1c2f9cfe), XV32(0x40cca5dd),
	XV32(0x2a171fb9), XV32(0x76f4269a), XV32(0x38009e84), XV32(0x64e3a7a7),
	XV32(0x7d0be3a4), XV32(0x21e8da87), XV32(0x6f1c6299), XV32(0x33ff5bba),
	XV32(0x5924e1de), XV32(0x5c7d8fd), XV32(0x4b3360e3), XV32(0x17d059c0),
	XV32(0x3555e750), XV32(0x69b6de73), XV32(0x2742666d), XV32(0x7ba15f4e),
	XV32(0x117ae52a), XV32(0x4d99dc09), XV32(0x36d6417), XV32(0x5f8e5d34),
	XV32(0x30bdec11), XV32(0x6c5ed532), XV32(0x22aa6d2c), XV32(0x7e49540f),
	XV32(0x1492ee6b), XV32(0x4871d748), XV32(0x6856f56), XV32(0x5a665675),
	XV32(0x78e3e8e5), XV32(0x2400d1c6), XV32(0x6af469d8), XV32(0x361750fb),
	XV32(0x5cccea9f), XV32(0x2fd3bc), XV32(0x4edb6ba2), XV32(0x12385281),
	XV32(0xbd01682), XV32(0x57332fa1), XV32(0x19c797bf), XV32(0x4524ae9c),
	XV32(0x2fff14f8), XV32(0x731c2ddb), XV32(0x3de895c5), XV32(0x610bace6),
	XV32(0x438e1276), XV32(0x1f6d2b55), XV32(0x5199934b), XV32(0xd7aaa68),
	XV32(0x67a1100c), XV32(0x3b42292f), XV32(0x75b69131), XV32(0x2955a812),
	XV32(0x271dc115), XV32(0x7bfef836), XV32(0x350a4028), XV32(0x69e9790b),
	XV32(0x332c36f), XV32(0x5fd1fa4c), XV32(0x11254252), XV32(0x4dc67b71),
	XV32(0x6f43c5e1), XV32(0x33a0fcc2), XV32(0x7d5444dc), XV32(0x21b77dff),
	XV32(0x4b6cc79b), XV32(0x178ffeb8), XV32(0x597b46a6), XV32(0x5987f85),
	XV32(0x1c703b86), XV32(0x409302a5), XV32(0xe67babb), XV32(0x52848398),
	XV32(0x385f39fc), XV32(0x64bc00df), XV32(0x2a48b8c1), XV32(0x76ab81e2),
	XV32(0x542e3f72), XV32(0x8cd0651), XV32(0x4639be4f), XV32(0x1ada876c),
	XV32(0x70013d08), XV32(0x2ce2042b), XV32(0x6216bc35), XV32(0x3ef58516),
	XV32(0x51c63433), XV32(0xd250d10), XV32(0x43d1b50e), XV32(0x1f328c2d),
	XV32(0x75e93649), XV32(0x290a0f6a), XV32(0x67feb774), XV32(0x3b1d8e57),
	XV32(0x199830c7), XV32(0x457b09e4), XV32(0xb8fb1fa), XV32(0x576c88d9),
	XV32(0x3db732bd), XV32(0x61540b9e), XV32(0x2fa0b380), XV32(0x73438aa3),
	XV32(0x6aabcea0), XV32(0x3648f783), XV32(0x78bc4f9d), XV32(0x245f76be),
	XV32(0x4e84ccda), XV32(0x1267f5f9), XV32(0x5c934de7), XV32(0x7074c4),
	XV32(0x22f5ca54), XV32(0x7e16f377), XV32(0x30e24b69), XV32(0x6c01724a),
	XV32(0x6dac82e), XV32(0x5a39f10d), XV32(0x14cd4913), XV32(0x482e7030),
	XV32(0x617bd822), XV32(0x3d98e101), XV32(0x736c591f), XV32(0x2f8f603c),
	XV32(0x4554da58), XV32(0x19b7e37b), XV32(0x57435b65), XV32(0xba06246),
	XV32(0x2925dcd6), XV32(0x75c6e5f5), XV32(0x3b325deb), XV32(0x67d164c8),
	XV32(0xd0adeac), XV32(0x51e9e78f), XV32(0x1f1d5f91), XV32(0x43fe66b2),
	XV32(0x5a1622b1), XV32(0x6f51b92), XV32(0x4801a38c), XV32(0x14e29aaf),
	XV32(0x7e3920cb), XV32(0x22da19e8), XV32(0x6c2ea1f6), XV32(0x30cd98d5),
	XV32(0x12482645), XV32(0x4eab1f66), XV32(0x5fa778), XV32(0x5cbc9e5b),
	XV32(0x3667243f), XV32(0x6a841d1c), XV32(0x2470a502), XV32(0x78939c21),
	XV32(0x17a02d04), XV32(0x4b431427), XV32(0x5b7ac39), XV32(0x5954951a),
	XV32(0x338f2f7e), XV32(0x6f6c165d), XV32(0x2198ae43), XV32(0x7d7b9760),
	XV32(0x5ffe29f0), XV32(0x31d10d3), XV32(0x4de9a8cd), XV32(0x110a91ee),
	XV32(0x7bd12b8a), XV32(0x273212a9), XV32(0x69c6aab7), XV32(0x35259394),
	XV32(0x2ccdd797), XV32(0x702eeeb4), XV32(0x3eda56aa), XV32(0x62396f89),
	XV32(0x8e2d5ed), XV32(0x5401ecce), XV32(0x1af554d0), XV32(0x46166df3),
	XV32(0x6493d363), XV32(0x3870ea40), XV32(0x7684525e), XV32(0x2a676b7d),
	XV32(0x40bcd119), XV32(0x1c5fe83a), XV32(0x52ab5024), XV32(0xe486907)
};

#endif /* if defined(XRABPLY_TYPE32) */

