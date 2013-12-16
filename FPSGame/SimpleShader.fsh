
varying vec3 vColorValues;

void main()
{
    vec3 colorValues = clamp(vColorValues, vec3(0.0), vec3(1.0));
    gl_FragColor = vec4(colorValues, 1.0);
}