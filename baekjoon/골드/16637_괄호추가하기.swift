//
//  main.swift
//  algostudy
//
//  Created by 강희선 on 2021/09/14.
//
import Foundation

let n = Int(readLine()!)!
let str = readLine()!.map{ String($0) }
let nums = str.filter{ guard Int($0) != nil else { return false }
    return true
}.map{ Int($0)! }
let ops = str.filter{ guard Int($0) == nil else { return false }
    return true
}

var Max: Int = Int.min
func cal(_ a: Int, _ b: Int, _ op: String) -> Int{
    if op == "+"{
        return a + b
    }else if op == "-"{
        return a - b
    }else{
        return a * b
    }
}
func dfs(_ idx: Int, _ result: Int){
    if(idx >= ops.count){
        Max = max(Max, result)
        return
    }
    let tmp = cal(result, nums[idx+1], ops[idx])
    dfs(idx+1, tmp)
    if idx+1 < ops.count{
        let tmp1 = cal(nums[idx+1], nums[idx+2], ops[idx+1])
        let tmp2 = cal(result, tmp1, ops[idx])
        dfs(idx+2, tmp2)
    }
}

dfs(0, nums[0])
print(Max)
