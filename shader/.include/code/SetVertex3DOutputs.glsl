#ifndef USING_VERTEX_TEXTURE_UV
    color = _color;
#else
    uv = _uv;
#endif
    normal = (_modelRotation * vec4(_normal, 1.0)).rgb;
    viewNormal = normalize(normal);
    position = (_modelMatrix * vec4(_positionInModel, 1.0)).rgb;