local t=f_newclass()

print("Create Class T");

function t:onLoad()
	self:setString("Hello World, This is ScriptUrl");
end

function t:onUpdate(dt)
	self:rotateZ(40*dt)
end

return t
