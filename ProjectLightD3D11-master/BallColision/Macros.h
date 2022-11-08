#pragma once
#define MouseIsInside math.CalculateLenght(spritelist[i].GetShape().point, wnd.mouse.GetMousePosition()) < spritelist[i].GetShape().radiusX
#define CreateRandomPlayerValues rand() % 1920*1.0f, rand() % 1080*1.0f,rand()*5000
#define CreatePlayerValuesAtMousePosition wnd.mouse.GetMousePosition().x, wnd.mouse.GetMousePosition().y,rand() * 10000