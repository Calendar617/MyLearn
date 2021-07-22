ShellSort = {}

local data = {}

local function InitData()
    print("Init Data")
    for i = 0, 20 do 
        data[i] = math.random( 0, 100)
        print("data[",i,"] = ", data[i])
    end
end

function div2(x)
    x = x / 2
    return x
end

function Check1(gap)
    return 1
end

function Check(x, y, data)
    return x >= y and data[x - y] < 0
end

function minusGap(j, gap)
    return j - gap
end

function ShellSort.Sort()
    InitData()
    print("Start Shell Sort")    
    local gap = math.modf(#data / 2)
    while(gap > 0)
    do
        for i = gap, #data do
            local temp = data[i]
            j = i
            while(j >= gap and temp <= data[j- gap])
            do            
              data[j] = data[j - gap]
              j = j - gap
            end
            data[j] = temp
        end
        gap = math.modf(gap /  2)
    end    
    printArry(data)
    print("End Shell Sort")
end

return ShellSort