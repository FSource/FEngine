$[

-- for for load and save table  
function  f_tabletostring(t,prefix)

	if not prefix then 
		prefix="" 
	end

	local result=""
	for k,v in pairs(t) do 
		local key_type=type(k)
		local value_type=type(v)
		local key_str 
		local value_str
		if key_type == "string" then 
			key_str = "\[\""..f_escstring(k).."\"\]"
		elseif key_type == "number" then 
			key_str = "\["..tostring(k).."\]"
		else 
			error(string.format("key for %s not support",key_type))
		end

		if value_type == "string" then 
			value_str = "\""..f_escstring(v).."\"" 

		elseif value_type == "number" or value_type == "boolean" or value_type == "nil" or value_type=="userdata" then  
			value_str = tostring(v)
		elseif value_type =="table" then 
			value_str = f_tabletostring(v,prefix.."\t")
		else 
			error(string.format("value for %s not support",value_type))
		end

		result = result.. prefix.."\t"..key_str.."="..value_str..",\n"
	end
	return "{\n"..result..prefix.."}"

end


function  f_savetable(filename,t,key)
	str=f_tabletostring(t);
	if key  then 
		str=f_xorstring(str,key)
	end
	f_savefile(filename,str)
end

function f_loadtable(filename,key)
	local str=f_loadfile(filename)

	if not str then 
		return nil 
	end

	if key then 
		str= f_xorstring(str,key)
	end
	str="return "..str 
	local chunk=loadstring(str,filename)

	if chunk  then 
		return chunk()
	end 
end


-- log 
function f_utillog(fmt,...)
	local str=string.format(fmt,...)
	f_log(str)
end


local l_loadmodule={}

function f_require(filename)
	if l_loadmodule[filename]~=nil then 
		return  l_loadmodule[filename];
	end

	local ret=f_dofile(filename)
	l_loadmodule[filename]=ret
	return ret

end


function f_newclass()
	local ret={}
	ret.__index=ret 
	return ret
end


function f_extends(o,c)
	if type(o)=="table" then 
		setmetatable(o,c)
	elseif type(o)=="userdata" then 
		if o.__fdata then 
			setmetatable(o.__fdata,c)
		else 
			o.__fdata={}
			setmetatable(o.__fdata,c)
		end
	else 
		f_utillog("not support type(%s) extends",type(o));
	end
end

function f_setattrenv(o,v)
	o.__fdata=v
end

function f_getattrenv(o)
	return o.__fdata
end


function f_setScriptUrl(o,url)
	local class=f_require(url)
	if not class then 
		return false
	end

	f_extends(o,class)
	o:assignScriptHook()
	o:onLoad()
	return true
end


$]

