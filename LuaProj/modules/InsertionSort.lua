
InsertionSort = {}
local data = {}

function swap(data, i, j)
    local temp = data[i]
    data[i] = data[j]
    data[j] = temp
end

function printArry(data)
    for i = 0, #data do         
        print("data[",i,"] = ", data[i])
    end
end

function InsertionSort.Sort()
    print("Init Data")
    for i = 0, 20 do 
        data[i] = math.random( 0, 100)
        print("data[",i,"] = ", data[i])
    end

    print("Start Insertion Sort")
    for i = 0, #data do 
        for j = i, 1, -1 do
            if data[j] < data[j - 1] then
                swap(data, j, j - 1)
            else
                break
            end
        end
    end
    printArry(data)
    print("End Insertion Sort")
end

return InsertionSort