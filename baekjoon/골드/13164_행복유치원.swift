//
//  main.swift
//  study
//
//  Created by 강희선 on 2021/09/28.
//

import Foundation


let nk = readLine()!.split(separator: " ").map{ Int(String($0))! }
let n = nk[0], k = nk[1]
let children = readLine()!.split(separator: " ").map{ Int(String($0))! }

var diffs: [Int] = []
var prev = children[0]
for i in 1..<children.count{
    let diff = children[i]-prev
    diffs.append(diff)
    prev = children[i]
}

diffs.sort(by: <)
var sum = 0
for i in 0..<n-k{
    sum += diffs[i]
}

print(sum)
