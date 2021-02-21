function [ surface_area ] = sarea( radius, height )
    surface_area  = (2* pi .* height  .* radius) + 2 * pi .* (radius^2)
end