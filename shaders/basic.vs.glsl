attribute vec3 a_posCoord;
attribute vec2 a_texCoord;

varying vec2 v_texCoord;
varying vec4 v_colValue;

uniform mat4 u_transform;

void main(void) {
    //v_colValue = vec4(clamp(a_posCoord, 0.0, 1.0), 1.0);
    v_colValue = vec4(1.0, 1.0, 1.0, 1.0);
    gl_Position = u_transform * vec4(a_posCoord, 1.0);
    v_texCoord = a_texCoord;

}
