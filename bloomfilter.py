#!/usr/bin/env python
# coding=utf-8

from BitVector import BitVector


class BloomFilter(object):
    """
    布隆过滤器
    """
    def __init__(self, n):
        super(BloomFilter, self).__init__()
        self.n = n
        self.bits = BitVector(size=n)

    def __hashcodes(self, val):
        """
        供布隆过滤器使用的哈希函数
        seed: 种子
        val : 被哈希的字符串
        """
        results = []
        seeds = [3, 5, 7, 11, 13, 31, 37, 61]
        for seed in seeds:
            result = 0
            for v in val:
                result = seed * result + ord(v)
            results.append((self.n - 1) & result)
        return results

    def has(self, val):
        """
        根据哈希函数进行过滤，返回True或False
        使用不同种子构建8个不同的哈希函数
        """
        hash_pos = self.__hashcodes(val)
        has = True
        for i in hash_pos:
            if not self.bits[i]:
                self.bits[i] = 1
                has = False
        return has

if __name__ == '__main__':
    bloomFilter = BloomFilter(1000000)
    examples = ['http://www.baidu.com',
                'http://s1.bdstatic.com/r/www/img/i-1.0.0.png',
                'http://s1.bdstatic.com/r/www/img/i-1.0.0.png',
                'http://www.baidu.com/gaoji/preferences.html',
                'http://news.baidu.com',
                'http://news.baidu.com']
    for e in examples:
        print bloomFilter.has(e)