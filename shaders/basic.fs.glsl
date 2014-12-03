varying vec2 v_texCoord;

uniform vec3 u_color;
uniform sampler2D sampler;

void main(void) {

    vec4 texColor = texture2D(sampler, v_texCoord);

    if (texColor.x == 0.0 && texColor.y == 0.0)
        gl_FragColor = vec4(u_color, 1.0);
    else
        gl_FragColor = texColor * vec4(u_color, 1.0);
}
