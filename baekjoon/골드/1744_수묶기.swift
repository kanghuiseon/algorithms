//
//  main.swift
//  study
//
//  Created by 강희선 on 2021/09/28.
//

import Foundation


let n = Int(String(readLine()!))!
var plus: [Int] = []
var minus: [Int] = []
var sum = 0
var zero = 0
for _ in 0..<n{
    let tmp = readLine(strippingNewline: false)!.split(separator: "\n").map{ Int(String($0))! }
    if tmp[0] == 1{
        sum += 1
    }else if tmp[0]  == 0{
        zero += 1
    }else if tmp[0] > 0 {
        plus.append(tmp[0])
    }else if tmp[0] < 0{
        minus.append(tmp[0])
    }
}
plus.sort(by: >)
minus.sort(by: <)
if plus.count % 2 == 1{
    plus.append(1)
}
if minus.count % 2 == 1{
    if zero == 0{
        minus.append(1)
    }else{
        minus.append(0)
    }
}

for i in stride(from: 0, to: plus.count, by: 2){
    sum += plus[i] * plus[i+1]
}
for i in stride(from: 0, to: minus.count, by: 2){
    sum += minus[i] * minus[i+1]
}

print(sum)
